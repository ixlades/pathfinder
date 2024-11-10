#include "../inc/pathfinder.h"


void print_path_block(int **graph, char **names, const int *current_path, int goal) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(names[current_path[0]]);
    mx_printstr(" -> ");
    mx_printstr(names[goal]);
    mx_printchar('\n');

    mx_printstr("Route: ");
    for (int k = 0; current_path[k] != -1; ++k) {
        mx_printstr(names[current_path[k]]);
        if (current_path[k + 1] != -1) mx_printstr(" -> ");
    }
    mx_printstr("\nDistance: ");
    int path = 0;

    for (int k = 0; current_path[k] != -1; ++k) {
        if (current_path[k + 1] != -1 && graph[current_path[k]][current_path[k + 1]] != -1) {
            path += graph[current_path[k]][current_path[k + 1]];
            mx_printint(graph[current_path[k]][current_path[k + 1]]);

            if (current_path[k + 2] != -1) {
                mx_printstr(" + ");
            } else if (current_path[k + 2] == -1 && k > 0) {
                mx_printstr(" = ");
                mx_printint(path);
                break;
            }
        }

    }
    mx_printchar('\n');
    mx_printstr("========================================\n");

}

