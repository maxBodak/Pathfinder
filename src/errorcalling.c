#include "pathfinder.h"

void errorInline(unsigned int line_num) {
    char *err = mx_itoa(line_num);

    mx_printerr("error: line ");
    mx_printerr(err);
    mx_printerr(" is not valid\n");
    free(err);
    exit(1);
}
void errorDupbridges() {
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}
void errorIslenum() {
    mx_printerr("error: invalid number of islands\n");
    exit(1);
}
