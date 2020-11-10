#include "pathfinder.h"


static void checkArgs(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
static int isOpen(char *argv[]) {
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    return fd;
}
int main(int argc, char *argv[]) {
    t_map *map = NULL;
    int fd;

    checkArgs(argc);
    fd = isOpen(argv);
    formMap(&map, fd, argv);
    buildMatrix(map);
    //system("leaks -q pathfinder");
    return 0;
}
