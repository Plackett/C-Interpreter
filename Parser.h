#pragma once
#ifndef PARSER
#define PARSER

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "Components.h"

class Parser
{
public:
	char* currentData;

	Parser(char* line)
	{
		currentData = line;
	}

	void parse(LukeComputer cpu) const;
};

#endif