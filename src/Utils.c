#include "Utils.h"


/**
 * Function to read a byte
 * @param cpu
 * @param address
 * @return the value of the byte of the cpu at that address
 */
uint8_t read_byte(struct i8080* cpu, uint16_t address){
    return cpu->read_byte(cpu->user_address, address);
}
/**
 * Function to write a byte
 * @param cpu, processor in which it is saved
 * @param address where it is saved
 * @param value writen
 */
void write_byte(struct i8080* cpu, uint16_t address, uint8_t value){
    cpu->write_byte(cpu->user_address, address, value);
}
/**
 * Function to read the following byte
 * @param cpu, processor
 * @return the value of the next byte
 */
uint8_t next_byte(struct i8080* cpu){
    return read_byte(cpu, cpu->reg.PC++);
}
/**
 * Function to read a full word given the address
 * @param cpu
 * @param address
 * @return the full value of the word
 */
uint16_t read_word(struct i8080* cpu, uint16_t address) {
    return cpu->read_byte(cpu->user_address, address + 1) << 8 |
           cpu->read_byte(cpu->user_address, address);
}
/**
 * Function to write a full word in memory
 * @param cpu
 * @param address
 * @param value
 */
void write_word(struct i8080* cpu, uint16_t address, uint8_t value){
    cpu->write_byte(cpu->user_address, address, value & 0xFF);
    cpu->write_byte(cpu->user_address, address + 1, value >> 8);
}
/**
 * Function to read the following word
 * @param cpu
 * @return the value of the next word
 */
uint16_t next_word(struct i8080* cpu) {
    uint16_t next_value = read_word(cpu, cpu->reg.PC);
    cpu->reg.PC += 2;
    return next_value;
}
/**
 * Function to check the parity of a byte
 * @param value
 * @return
 */
uint8_t parity(uint8_t value){
    uint8_t ones = 0;
    for (int i = 0; i < 8; i++){
        ones += ((value >> i) & 1);
    }
    return (ones & 1) == 0;
}
/**
 * Calculating if there is a carry in the operation
 * @param bit_nb: number of bits of the ints
 * @param a: number 1
 * @param b: number 2
 * @param carry_flag: flag if there was already carry
 * @return the final carry after the operation
 */
bool carry(int bit_nb, uint8_t a, uint8_t b, bool carry_flag){
    int16_t result = a + b + carry_flag;
    int16_t carry = result ^ a ^ b;
    return carry & (1 << bit_nb);
}
/**
 * Function to set the registers BC
 * @param cpu
 * @param value
 */
void set_BC (struct i8080* cpu, uint16_t value){
    cpu->reg.B = value >> 8;
    cpu->reg.C = value & 0xFF;
}
/**
 * Function to set the registers DE
 * @param cpu
 * @param value
 */
void set_DE (struct i8080* cpu, uint16_t value){
    cpu->reg.D = value >> 8;
    cpu->reg.E = value & 0xFF;
}
/**
 * Function to set the registers HL
 * @param cpu
 * @param value
 */
void set_HL (struct i8080* cpu, uint16_t value){
    cpu->reg.H = value >> 8;
    cpu->reg.L = value & 0xFF;
}
/**
 * Function to get the value of register BC
 * @param cpu
 * @return
 */
uint16_t get_BC (struct i8080* cpu){
    return (cpu->reg.B << 8) | cpu->reg.C;
}
/**
 * Function to get the value of register DE
 * @param cpu
 * @return
 */
uint16_t get_DE (struct i8080* cpu){
    return (cpu->reg.D << 8) | cpu->reg.E;
}
/**
 * Function to get the value of register HL
 * @param cpu
 * @return
 */
uint16_t get_HL (struct i8080* cpu){
    return (cpu->reg.H << 8) | cpu->reg.L;
}