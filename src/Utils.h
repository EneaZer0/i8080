#ifndef I8080_UTILS_H
#define I8080_UTILS_H

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

#include "Main - i8080.h"

uint8_t read_byte(struct Main* cpu, uint16_t address);
void write_byte(struct Main* cpu, uint16_t address, uint8_t value);
uint16_t read_word(struct Main* cpu, uint16_t address);
void write_word(struct Main* cpu, uint16_t address, uint8_t value);
uint8_t next_byte(struct Main* cpu);
uint16_t next_word(struct Main* cpu);


#endif //I8080_UTILS_H
