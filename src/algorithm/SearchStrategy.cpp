// Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
// Distributed under the terms of the GNU General Public License, version 3

#include "algorithm/SearchStrategy.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

long parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    long i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atol(p);
    return i;
}

long getValue(){
    FILE* file = fopen("/proc/self/status", "r");
    long result = -1;
    char line[128];

    while (fgets(line, 128, file) != nullptr){
        if (strncmp(line, "VmPeak:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    if(result != -1) result *= 1000; // kB to B
    return result;
}

SearchStrategy::failed_to_find_solution::failed_to_find_solution(const std::string &s) :
    logic_error(s)
{
}

SearchStrategy::~SearchStrategy() = default;

size_t SearchStrategy::getMemory() const {
    return static_cast<size_t>(getValue());
}
