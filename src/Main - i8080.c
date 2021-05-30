#include "Main - i8080.h"

#define SET_FLAGS(cpu, value) do{       \
    cpu->flags.Zero == 0;               \
    cpu->flags.Sign >>7                 \
    cpu->flags.Parity = parity(value)   \
} while(0)

/**
 * Initialisation function of the CPU i8080 - i8080
 * @param cpu struct with all the elements of the i8080 - i8080
 */
void initialise(struct i8080* cpu){
    // Setup registers
    cpu->reg.A  = 0;
    cpu->reg.B  = 0;
    cpu->reg.C  = 0;
    cpu->reg.D  = 0;
    cpu->reg.E  = 0;
    cpu->reg.H  = 0;
    cpu->reg.L  = 0;

    cpu->reg.PC = 0;
    cpu->reg.SP = 0;

    // Setup flags
    cpu->flags.Zero               = 0;
    cpu->flags.Sign               = 0;
    cpu->flags.Parity             = 0;
    cpu->flags.Carry              = 0;
    cpu->flags.Auxiliary_Carry    = 0;
    cpu->flags.InterruptFlip_Flop = 0;
}
//TODO
static inline void execute(struct i8080* cpu, uint8_t Opcode){
    //TODO
}
/**
 * Executing one instruction
 * @param cpu, if interrupt pending and InterruptFlip_Flop is set -> execute vector of user
 */
void execute_instruction(struct i8080* cpu){
    if (cpu->flags.InterruptFlip_Flop && cpu->state.interrupt_pending && cpu->state.interrupt_delay == 0) {
        cpu->state.interrupt_pending = 0;
        cpu->flags.InterruptFlip_Flop = 0;
        cpu->state.halted = 0;

        execute(cpu, cpu->state.interrupt_vector);
    }
    else if (!cpu->state.halted) {
        execute(cpu, next_byte(cpu));
    }

}

void interrupt(struct i8080* cpu, uint8_t opcode){
    cpu->state.interrupt_pending = 1;
    cpu->state.interrupt_vector = opcode;
}
///////////////////////////////////////////////
/// OPENING AND READING AN ASSEMBLY PROGRAM
///////////////////////////////////////////////
int main(void) {
    // allocating the memory
    memory = malloc(MEMORY_SIZE);
    if (memory == NULL) return 1;
    printf("all right!!!");
    return 0;
}
