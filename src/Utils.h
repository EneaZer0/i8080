#ifndef I8080_UTILS_H
#define I8080_UTILS_H

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

#include "Main - i8080.h"

///////////////////////////////////////////////
/// MEMORY ACCESS DECLARATIONS
///////////////////////////////////////////////
uint8_t read_byte(struct i8080* cpu, uint16_t address);
void write_byte(struct i8080* cpu, uint16_t address, uint8_t value);
uint16_t read_word(struct i8080* cpu, uint16_t address);
void write_word(struct i8080* cpu, uint16_t address, uint8_t value);
uint8_t next_byte(struct i8080* cpu);
uint16_t next_word(struct i8080* cpu);

///////////////////////////////////////////////
/// LOGICAL OPERATIONS DECLARATIONS
///////////////////////////////////////////////
uint8_t parity(uint8_t value);
bool carry(int bit_nb, uint8_t a, uint8_t b, bool carry_flag);

///////////////////////////////////////////////
/// REGISTER SETTERS
///////////////////////////////////////////////
void set_BC (struct i8080* cpu, uint16_t value);
void set_DE (struct i8080* cpu, uint16_t value);
void set_HL (struct i8080* cpu, uint16_t value);

///////////////////////////////////////////////
/// REGISTER GETTERS
///////////////////////////////////////////////
uint16_t get_BC (struct i8080* cpu);
uint16_t get_DE (struct i8080* cpu);
uint16_t get_HL (struct i8080* cpu);

#endif //I8080_UTILS_H
