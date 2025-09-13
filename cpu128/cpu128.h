#ifndef CPU128_H
#define CPU128_H

#include <stdint.h>

typedef unsigned __int128 uint128;

typedef struct {
    uint128 regA;
    uint128 regB;
    uint128 acc;
    uint128 pc;
    int flagZ;
    int flagN;
    uint64_t clock;
} CPU128;

#define RAM_SIZE 256
extern uint128 RAM[RAM_SIZE];

// Funciones básicas
void print_uint128(uint128 value);
void LOAD_A(CPU128 *cpu, uint128 val);
void LOAD_B(CPU128 *cpu, uint128 val);
void ADD_AB(CPU128 *cpu);
void SUB_AB(CPU128 *cpu);
void MUL_AB(CPU128 *cpu);
void DIV_AB(CPU128 *cpu);
void INC_A(CPU128 *cpu);
void INC_B(CPU128 *cpu);
void DEC_A(CPU128 *cpu);
void DEC_B(CPU128 *cpu);
void AND_AB(CPU128 *cpu);
void OR_AB(CPU128 *cpu);
void XOR_AB(CPU128 *cpu);
void NOT_A(CPU128 *cpu);
void NOT_B(CPU128 *cpu);
void STORE(CPU128 *cpu, int addr);
void LOAD(CPU128 *cpu, int addr);
void JUMP(CPU128 *cpu, uint128 addr);
void JUMPZ(CPU128 *cpu, uint128 addr);
void JUMPNZ(CPU128 *cpu, uint128 addr);

#endif
