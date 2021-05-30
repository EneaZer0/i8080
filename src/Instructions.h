#ifndef I8080_INSTRUCTIONS_H
#define I8080_INSTRUCTIONS_H

#include "Main - i8080.h"
#include "Utils.h"

#define SET_FLAGS(cpu, value) \
  do { \
    cpu->flags.Zero = (value) == 0; \
    cpu->flags.Sign = (value) >> 7; \
    cpu->flags.Parity = parity(value); \
  } while (0)

void add (struct i8080* cpu, uint8_t* reg, uint8_t value, bool carry_f);
void sub (struct i8080* cpu, uint8_t* reg, uint8_t value, bool carry_f);
void dad (struct i8080* cpu, uint16_t value);
#endif //I8080_INSTRUCTIONS_H
