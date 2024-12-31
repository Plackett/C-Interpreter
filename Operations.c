#include "Operations.h"
#include <stdlib.h>
#include "Components.h"
#include <stdio.h>

void identifyOperation(char** operation, int length, LukeComputer cpu)
{
    if (length < 2) {
        fprintf(stderr, "Invalid operation length.\n");
        return;
    }

    int* operands = (int*)malloc(sizeof(int) * (length - 1));

    for (int i = 1; i < length; i++) {
        operands[i - 1] = atoi(operation[i]);
    }

    int opcode = atoi(operation[0]);
    runOperation(opcode, operands, length - 1, cpu);

    free(operands);
}

void runOperation(int opcode, int* operands, int operandLength, LukeComputer cpu)
{

    int destination = 0, source = 0;

    switch (opcode)
    {
    // ADD
    case 0:
        if (operandLength < 2) {
            fprintf(stderr, "ADD operation requires at least two operands.\n");
            return;
        }

        destination = operands[0];
        if (destination < 0) {
            fprintf(stderr, "Invalid destination register: %d\n", destination);
            return;
        }

        for (int i = 1; i < operandLength; i++) {
            source = operands[i];
            if (source < 0) {
                fprintf(stderr, "Invalid source register: %d\n", source);
                return;
            }

            cpu.registers[destination] += cpu.registers[source];
        }

        printf("RESULT OF ADDITION: %i\n", cpu.registers[destination]);
        break;

    default:
        fprintf(stderr, "Unknown opcode: %d\n", opcode);
        break;
    }
}