#include "pathfinder.h"

static void initMap(t_map **map, unsigned int isle_num) {
    *map = malloc(sizeof (t_map));
    (*map)->iNum = 0;
    (*map)->total_len = 0;
    (*map)->stated_iNum = isle_num;
    (*map)->iArr = malloc(sizeof(char *) * isle_num);
    (*map)->bx = (bool **)malloc(sizeof(bool *) * isle_num);
    (*map)->mx = (unsigned int **)malloc(sizeof(int *) * isle_num);
    for (unsigned int i = 0; i < isle_num; i++) {
        (*map)->iArr[i] = NULL;
        (*map)->bx[i] = (bool *)malloc(sizeof(bool) * isle_num);
        (*map)->mx[i] = (unsigned int *)malloc(sizeof(int) * isle_num);
        for (unsigned int j = 0; j < isle_num; j++) {
            if (i == j) {
                (*map)->mx[i][j] = 0;
                (*map)->bx[i][j] = true;
            } else {
                (*map)->bx[i][j] = false;
                (*map)->mx[i][j] = INT_MAX;
            }
        }
    }
}
static void addBridge(t_map *map, unsigned int a, unsigned int b,
                        unsigned int len) {
    if (map->bx[a][b])
            errorDupbridges();
    map->mx[a][b] = len;
    map->mx[b][a] = len;
    map->bx[a][b] = true;
    map->bx[b][a] = true;
    map->total_len += len;
}
static unsigned int addIsle(t_map *map, char *name) {
    int i;

    for (i = 0; map->iArr[i] != NULL; i++)
        if (!mx_strcmp(map->iArr[i], name))
            return i;
    map->iNum++;
    if (map->iNum > map->stated_iNum)
        errorIslenum();
    map->iArr[i] = mx_strdup(name);
    return i;
}
static bool parseLine(t_map *map, char *line, unsigned int count) {
    if(*line == '\0')
        return true;
    checkLine(line, count);

    unsigned int a, b;
    unsigned long len;
    char *temp = mx_strchr(line, '-');

    *temp = '\0';
    temp++;
    a = addIsle(map, line);

    line = temp;
    temp = mx_strchr(temp, ',');
    *temp = '\0';
    b = addIsle(map, line);
    temp++;
    len = mx_atol(temp);
    if (a == b)
        errorInline(count);
    addBridge(map, a, b, len);
    return false;
}
void formMap(t_map **map, int fd, char *argv[]) {
    char *line = NULL;
    int rd = mx_read_line(&line, 10, '\n', fd);
    bool last_line;

    checkEmptyFile(rd, argv);
    checkFirstLine(line);
    initMap(map, mx_atoi(line));
    rd = mx_read_line(&line, 10, '\n', fd);
    for (int i = 2; rd != -1; i++) {
        last_line = parseLine(*map, line, i);
        rd = mx_read_line(&line, 10, '\n', fd);
        if ((last_line && rd != -1) || (!last_line && rd == -1))
            errorInline(i);
    }
    checkIsleNum(*map);
    checkBridgeLen(*map);
    free(line);
}
