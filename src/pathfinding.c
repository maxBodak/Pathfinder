#include "pathfinder.h"

static void printSolvedPath(t_map *map, unsigned int *path, unsigned int len) {
    mx_printstr("========================================\nPath: ");
    mx_printstr(map->iArr[path[0]]);
    mx_printstr(" -> ");
    mx_printstr(map->iArr[path[len - 1]]);
    mx_printstr("\nRoute: ");
    for (unsigned int i = 0; i < len - 1; i++) {
        mx_printstr(map->iArr[path[i]]); 
        mx_printstr(" -> ");
    }
    mx_printstr(map->iArr[path[len - 1]]); 
    mx_printstr("\nDistance: ");
    if (len > 2) {
        for (unsigned int i = 1; i < len; i++) {
            if (i != 1)
                mx_printstr(" + ");
            mx_printint(map->mx[path[i - 1]][path[i]]); 
        }
        mx_printstr(" = ");
    }
    mx_printint(map->mx[path[0]][path[len - 1]]); 
    mx_printstr("\n========================================\n"); 
}
static void solvePathRec(t_map *map, unsigned int st, unsigned int fin, 
                            unsigned int *path, unsigned int len) {
    if (st == fin) {
        printSolvedPath(map, path, len);
        return;
    }
    len++;
    for (unsigned int i = 0; i < map->iNum; i++)
        if (map->bx[st][i] && st != i)
            if (map->mx[st][i] + map->mx[i][fin] == map->mx[st][fin]) {
                path[len - 1] = i;
                solvePathRec(map, i, fin, path, len);
            }
}
static void printAllPaths(t_map *map) {
    unsigned int *path = malloc(sizeof(int) * map->iNum);

    for (unsigned int st = 0; st < map->iNum; st++) {
        path[0] = st;
        for (unsigned int fin = st + 1; fin < map->iNum; fin++)
                solvePathRec(map, st, fin, path, 1);
    }
    free(path);
}
void buildMatrix(t_map *map) {
    for (unsigned int k = 0; k < map->iNum; k++)
        for (unsigned int i = 0; i < map->iNum; i++)
            for (unsigned int j = i + 1; j < map->iNum; j++)
                 if (map->mx[i][j] > map->mx[i][k] + map->mx[k][j]) {
                    map->mx[i][j] = map->mx[i][k] + map->mx[k][j];
                    map->mx[j][i] = map->mx[i][k] + map->mx[k][j];
                    map->bx[i][j] = false;
                    map->bx[j][i] = false;
                 }
    printAllPaths(map);
}
