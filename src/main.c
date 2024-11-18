#include "../inc/pathfinder.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("Usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    char *filename = argv[1];
    pathfinder(filename);

    return 0;
}


