#include "cpu128.h"
#include <stdio.h>
#include <time.h>

void print_cpu_state(CPU128 *cpu, int ram_show) {
    printf("=== CPU128 STATE ===\n");
    printf("regA: "); print_uint128(cpu->regA); printf("\n");
    printf("regB: "); print_uint128(cpu->regB); printf("\n");
    printf("acc : "); print_uint128(cpu->acc); printf("\n");
    printf("PC  : "); print_uint128(cpu->pc); printf("\n");
    printf("flagZ: %d, flagN: %d\n", cpu->flagZ, cpu->flagN);
    printf("Clock cycles: %llu\n", (unsigned long long)cpu->clock);

    printf("RAM: ");
    for(int i=0; i<ram_show; i++) {
        print_uint128(RAM[i]); printf(" ");
    }
    printf("\n==================\n\n");
}

int main() {
    CPU128 cpu = {0};

    // Obtener hora actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Representar la hora como número de 128 bits: HHMMSS
    uint128 hora128 = (uint128)(tm.tm_hour*10000 + tm.tm_min*100 + tm.tm_sec);

    // Cargar la hora en acc
    LOAD_A(&cpu, hora128);

    // Operaciones de ejemplo
    LOAD_B(&cpu, 123456);
    ADD_AB(&cpu); STORE(&cpu, 0);
    SUB_AB(&cpu); STORE(&cpu, 1);
    MUL_AB(&cpu); STORE(&cpu, 2);
    DIV_AB(&cpu); STORE(&cpu, 3);

    AND_AB(&cpu); STORE(&cpu, 4);
    OR_AB(&cpu);  STORE(&cpu, 5);
    XOR_AB(&cpu); STORE(&cpu, 6);
    NOT_A(&cpu);  STORE(&cpu, 7);

    // Mostrar estado completo del CPU
    print_cpu_state(&cpu, 8);

    return 0;
}
