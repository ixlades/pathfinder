#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>

typedef struct {
    int* route;
    int length;
    int start;
    int goal;
} t_path;

typedef struct {
    int** graph;
    int* distance;
    int** previous;
    int* prev_count;
    int num_islands;
} t_graph_context;

typedef struct {
    int start;
    int goal;
    int* path;
    int path_length;
    t_path** collected_paths;
    int* path_count;
} t_recovery_state;


int mx_atoi(const char *str);
void pathfinder(const char *filename);
t_path* deikstra(int num_islands, int** graph, int start, int* path_count);

void graph_fill(const int fd, int **graph, char **names, const int size);
int **graph_init(const int size);
void print_path_block(int **graph, char **names, const int *current_path, int goal);
void bubble_sort_paths(t_path *paths, int path_count);

void free_core_memory(int **graph, char **names, const int size);
void free_connections(int **connections, const int size);


#endif
