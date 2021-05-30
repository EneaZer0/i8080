#include "Instructions.h"

/**
 * Function to add a value to a register
 * @param cpu
 * @param reg
 * @param value
 * @param carry_f
 */
void add (struct i8080* cpu, uint8_t* reg, uint8_t value, bool carry_f){
    uint8_t result = *reg + value + carry_f;
    cpu->flags.Carry = carry(8, *reg, value, carry_f);
    cpu->flags.Auxiliary_Carry = carry(4, *reg, value, carry_f);
    SET_FLAGS(cpu, result);
    *reg = result;
}
/**
 * Function to subtract a value to a register
 * @param cpu
 * @param reg
 * @param value
 * @param carry_f
 */
void sub (struct i8080* cpu, uint8_t* reg, uint8_t value, bool carry_f){
    add(cpu, reg, ~value, !carry_f);
}
/**
 * Function to add a value/word to HL registers
 * @param cpu
 * @param value
 */
void dad (struct i8080* cpu, uint16_t value){
    cpu->flags.Carry = ((get_HL(cpu) + value) >> 16) & 1;
    set_HL(cpu, get_HL(cpu) + value);
}