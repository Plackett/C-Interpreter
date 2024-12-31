#pragma once
#ifndef LUKEPUTER
#define LUKEPUTER

#include <stdlib.h>

class LukeComputer
{
public:
	int* registers;
	LukeComputer(int regNumber)
	{
		registers = (int*)malloc(sizeof(int) * regNumber);
	}
};

#endif