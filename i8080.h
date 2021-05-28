//
// Created by EneaZero on 28/05/2021.
//

#ifndef I8080_I8080_H
#define I8080_I8080_H

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"

typedef  struct flag_Codes{

} flag_Codes;

typedef struct Registers_i8080{
    uint8_t A; // Accumulator  // Reg 7

    uint8_t B; // Reg 0
    uint8_t C; // Reg 1
    uint8_t D; // Reg 2
    uint8_t E; // Reg 3
    uint8_t H; // Reg 4
    uint8_t L; // Reg 5

    uint16_t SP; // Stack Point
    uint16_t PC; // Program counter

    uint8_t *memory; // RAM of i8080

}Registers_i8080;


#endif //I8080_I8080_H
