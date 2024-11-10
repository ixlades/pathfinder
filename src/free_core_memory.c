#include "../inc/pathfinder.h"

void free_connections(int **connections, const int size) {
    for(int j = 0; j < size; j++) {
        free(connections[j]);
    }
    free(connections);
}
void free_core_memory(int **graph, char **names, const int size) {
    for (int k = 0; k < size; k++) {
        mx_strdel(&names[k]);
        free(graph[k]);
    }
    free(graph);
    free(names);
}

