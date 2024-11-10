#include "../inc/pathfinder.h"

int **graph_init(const int size) {
    int **graph = malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {
        graph[i] = (int *)malloc(sizeof(int) * size);

        for (int j = 0; j < size; j++) {
            graph[i][j] = (i == j) ? 0 : -1;
        }
    }
    return graph;
}

