#ifndef I8080_MAIN_I8080_H
#define I8080_MAIN_I8080_H

#include "Utils.h"
#include "Instructions.h"

///////////////////////////////////////////////
/// DEFINE MEMORY SIZE
///////////////////////////////////////////////
#define MEMORY_SIZE 0x10000 // 65.536 bytes of memory
static uint8_t* memory = NULL;

///////////////////////////////////////////////
/// CONDITIONAL FLAG CODES
///////////////////////////////////////////////
typedef  struct Conditional_Flag_Codes{
    uint8_t Zero;
    uint8_t Sign;
    uint8_t Parity;
    uint8_t Carry;
    uint8_t Auxiliary_Carry;
    uint8_t InterruptFlip_Flop;
} Conditional_Flag_Codes;

///////////////////////////////////////////////
/// REGISTERS AND MEMORY ELEMENTS
///////////////////////////////////////////////
typedef struct Registers_i8080{
    uint8_t A; // Accumulator - Reg 7 111

    uint8_t B; // Reg 0 000
    uint8_t C; // Reg 1 001
    uint8_t D; // Reg 2 010
    uint8_t E; // Reg 3 011
    uint8_t H; // Reg 4 100
    uint8_t L; // Reg 5 101
               // Reg 6 110 Memory Reference M
    uint16_t SP; // Stack Point
    uint16_t PC; // Program counter

}Registers_i8080;

///////////////////////////////////////////////
/// STATE VARIABLES
///////////////////////////////////////////////
typedef struct State{
    bool halted:1;

    uint8_t interrupt_pending:1;
    uint8_t interrupt_vector;
    uint8_t interrupt_delay;

} State;

///////////////////////////////////////////////
/// i8080 - i8080 PROCESSOR
///////////////////////////////////////////////
typedef struct i8080{
    uint8_t (*read_byte) (void*, uint16_t);
    void (*write_byte) (void*, uint16_t, uint8_t);

    unsigned long cycles;         // counter of cycles
    Registers_i8080 reg;          // Adding registers
    Conditional_Flag_Codes flags; // Adding conditional flags
    State state;                  // Adding states conditions

    void* user_address;

} i8080;


void initialise(struct i8080* cpu);
void execute_instruction(struct i8080* cpu);
void interrupt(struct i8080* cpu, uint8_t opcode);

#endif //I8080_MAIN_I8080_H
