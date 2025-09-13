#include "cpu128.h"
#include <stdio.h>

uint128 RAM[RAM_SIZE];

void print_uint128(uint128 value) {
    if (value > 9) print_uint128(value / 10);
    putchar('0' + (int)(value % 10));
}

// Función para actualizar flags
void update_flags(CPU128 *cpu, uint128 value) {
    cpu->flagZ = (value == 0);
    cpu->flagN = (value >> 127) & 1; // bit más alto
}

// Cargar registros
void LOAD_A(CPU128 *cpu, uint128 val) { cpu->regA = val; cpu->pc++; cpu->clock++; }
void LOAD_B(CPU128 *cpu, uint128 val) { cpu->regB = val; cpu->pc++; cpu->clock++; }

// Operaciones aritméticas
void ADD_AB(CPU128 *cpu) { cpu->acc = cpu->regA + cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void SUB_AB(CPU128 *cpu) { cpu->acc = cpu->regA - cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void MUL_AB(CPU128 *cpu) { cpu->acc = cpu->regA * cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void DIV_AB(CPU128 *cpu) { cpu->acc = (cpu->regB != 0 ? cpu->regA / cpu->regB : 0); update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void INC_A(CPU128 *cpu) { cpu->regA++; update_flags(cpu, cpu->regA); cpu->pc++; cpu->clock++; }
void INC_B(CPU128 *cpu) { cpu->regB++; update_flags(cpu, cpu->regB); cpu->pc++; cpu->clock++; }
void DEC_A(CPU128 *cpu) { cpu->regA--; update_flags(cpu, cpu->regA); cpu->pc++; cpu->clock++; }
void DEC_B(CPU128 *cpu) { cpu->regB--; update_flags(cpu, cpu->regB); cpu->pc++; cpu->clock++; }

// Operaciones lógicas
void AND_AB(CPU128 *cpu) { cpu->acc = cpu->regA & cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void OR_AB(CPU128 *cpu)  { cpu->acc = cpu->regA | cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void XOR_AB(CPU128 *cpu) { cpu->acc = cpu->regA ^ cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void NOT_A(CPU128 *cpu)  { cpu->acc = ~cpu->regA; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }
void NOT_B(CPU128 *cpu)  { cpu->acc = ~cpu->regB; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }

// RAM
void STORE(CPU128 *cpu, int addr) { if(addr<RAM_SIZE) RAM[addr]=cpu->acc; cpu->pc++; cpu->clock++; }
void LOAD(CPU128 *cpu, int addr)  { if(addr<RAM_SIZE) cpu->acc=RAM[addr]; update_flags(cpu, cpu->acc); cpu->pc++; cpu->clock++; }

// Saltos
void JUMP(CPU128 *cpu, uint128 addr) { cpu->pc = addr; cpu->clock++; }
void JUMPZ(CPU128 *cpu, uint128 addr) { if(cpu->flagZ) cpu->pc=addr; cpu->clock++; }
void JUMPNZ(CPU128 *cpu, uint128 addr) { if(!cpu->flagZ) cpu->pc=addr; cpu->clock++; }
