#include "Parser.h"
#include "Operations.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define _CRT_SECURE_NO_WARNINGS

void Parser::parse(LukeComputer cpu) const
{
    size_t maxTokens = strlen(currentData) / 2 + 1;
    char** delimited = (char**)malloc(sizeof(char*) * maxTokens);

    char* token = strtok(currentData, " ");
    int currentIndex = 0;

    while (token != NULL) {
        delimited[currentIndex] = (char*)malloc(strlen(token) + 1);
        if (!delimited[currentIndex]) {
            for (int i = 0; i < currentIndex; i++) {
                free(delimited[i]);
            }
            free(delimited);
            std::exit(-1);
        }
        strcpy(delimited[currentIndex], token);
        currentIndex++;
        token = strtok(NULL, " ");
    }

    identifyOperation(delimited, currentIndex, cpu);

    for (int i = 0; i < currentIndex; i++) {
        free(delimited[i]);
    }
    free(delimited);
}
