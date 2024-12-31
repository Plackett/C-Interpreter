#pragma once
#ifndef OPERATIONS
#define OPERATIONS
#include "Components.h"

void identifyOperation(char** operation, int length, LukeComputer cpu);

void runOperation(int opcode, int* operands, int operandLength, LukeComputer cpu);

#endif OPERATIONS