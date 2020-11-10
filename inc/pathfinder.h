#pragma once

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct s_map {
    char **iArr;
    unsigned int **mx;
    bool **bx;
    unsigned int iNum;
    unsigned int stated_iNum;
    unsigned long total_len;
}               t_map;

//extern t_map *map;

// Error calling functions
void errorInline(unsigned int line_num);
void errorDupbridges();
void errorIslenum();
// Error checking functions
void checkEmptyFile(int rd, char *argv[]);
void checkFirstLine(char *line);
void checkIsleNum(t_map *map);
void checkBridgeLen(t_map *map);
void checkLine(char *line, unsigned int count);
// File parsing function
void formMap(t_map **map, int fd, char *argv[]);
// Pathfinding function (using Floyd-Warshall algorithm)
void buildMatrix(t_map *map);
