#include "Parser.h"

int main(int argc, char** argv)
{
	LukeComputer cpu(3);
	cpu.registers[0] = 5;
	cpu.registers[1] = 5;
	cpu.registers[2] = 3;

	while (true)
	{
		printf("Enter your operation any length of operands, e.g. 01 01 01: \n");

		char line[100];

		if (fgets(line, sizeof(line), stdin) != NULL) {
			if (line[0] == '-')
				break;
			Parser p(line);
			p.parse(cpu);
		}
		else {
			printf("Error reading input.\n");
		}
	}
	
	return EXIT_SUCCESS;
}