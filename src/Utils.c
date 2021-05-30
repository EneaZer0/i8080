#include "Utils.h"


/**
 * Function to read a byte
 * @param cpu
 * @param address
 * @return the value of the byte of the cpu at that address
 */
uint8_t read_byte(struct Main* cpu, uint16_t address){
    return cpu->read_byte(cpu->user_address, address);
}
/**
 * Function to write a byte
 * @param cpu, processor in which it is saved
 * @param address where it is saved
 * @param value writen
 */
void write_byte(struct Main* cpu, uint16_t address, uint8_t value){
    cpu->write_byte(cpu->user_address, address, value);
}
/**
 * Function to read the following byte
 * @param cpu, processor
 * @return the value of the next byte
 */
uint8_t next_byte(struct Main* cpu){
    return read_byte(cpu, cpu->reg.PC++);
}
/**
 * Function to read a full word given the address
 * @param cpu
 * @param address
 * @return the full value of the word
 */
uint16_t read_word(struct Main* cpu, uint16_t address) {
    return cpu->read_byte(cpu->user_address, address + 1) << 8 |
           cpu->read_byte(cpu->user_address, address);
}
/**
 * Function to write a full word in memory
 * @param cpu
 * @param address
 * @param value
 */
void write_word(struct Main* cpu, uint16_t address, uint8_t value){
    cpu->write_byte(cpu->user_address, address, value & 0xFF);
    cpu->write_byte(cpu->user_address, address + 1, value >> 8);
}
/**
 * Function to read the following word
 * @param cpu
 * @return the value of the next word
 */
uint16_t next_word(struct Main* cpu) {
    uint16_t next_value = read_word(cpu, cpu->reg.PC);
    cpu->reg.PC += 2;
    return next_value;
}