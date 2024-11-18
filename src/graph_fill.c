#include "../inc/pathfinder.h"

int findOrAddIsland(char **islands, int *island_count, const char *name, const int size) {
    for (int i = 0; i < *island_count; i++) {
        if (mx_strcmp(islands[i], name) == 0) {
            return i;
        }
    }
    if (*island_count >= size) return -1;

    islands[*island_count] = mx_strdup(name);
    (*island_count)++;
    return *island_count - 1;
}

void graph_fill(const int fd, int **graph, char **names, const int size) {
    int **connections = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        connections[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            connections[i][j] = 0;
        }
    }

    int island_count = 0;
    char *island1 = NULL;
    char *island2 = NULL;
    char *chr_num = NULL;
    unsigned long length;
    int stop;
    int count_lines = 1;
    unsigned long bridges_sum = 0;

    while (true) {
        stop = mx_read_line(&island1, 1, '-', fd);
        if (stop == -1) {
            if (island_count != size) {
                close(fd);
                free_core_memory(graph, names, size);
                free_connections(connections, size);
                mx_printerr("error: invalid number of islands\n");
                exit(-1);
            }
            break;
        }
        count_lines++;
        if (!stop) {
            mx_strdel(&island1);
            free_connections(connections, size);
            free_core_memory(graph, names, size);
            close(fd);
            mx_printerr("error: line ");
            char *str_count_lines = mx_itoa(count_lines);
            mx_printerr(str_count_lines);
            mx_strdel(&str_count_lines);
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        for(int i = 0; island1[i] != '\0'; i++) {
            if (!mx_isalpha(island1[i])) {
                mx_strdel(&island1);
                free_connections(connections, size);
                free_core_memory(graph, names, size);
                close(fd);
                mx_printerr("error: line ");
                char *str_count_lines = mx_itoa(count_lines);
                mx_printerr(str_count_lines);
                mx_strdel(&str_count_lines);
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }
        stop = mx_read_line(&island2, 1, ',', fd);
        if (!stop) {
            mx_strdel(&island1);
            mx_strdel(&island2);
            free_connections(connections, size);
            free_core_memory(graph, names, size);
            close(fd);
            mx_printerr("error: line ");
            char *str_count_lines = mx_itoa(count_lines);
            mx_printerr(str_count_lines);
            mx_strdel(&str_count_lines);
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        for(int i = 0; island2[i] != '\0'; i++) {
            if (!mx_isalpha(island2[i])) {
                mx_strdel(&island1);
                mx_strdel(&island2);
                free_connections(connections, size);
                free_core_memory(graph, names, size);
                close(fd);
                mx_printerr("error: line ");
                char *str_count_lines = mx_itoa(count_lines);
                mx_printerr(str_count_lines);
                mx_strdel(&str_count_lines);
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }

        if (mx_strcmp(island1, island2) == 0) {
            mx_strdel(&island1);
            mx_strdel(&island2);
            free_connections(connections, size);
            free_core_memory(graph, names, size);
            close(fd);
            mx_printerr("error: line ");
            char *str_count_lines = mx_itoa(count_lines);
            mx_printerr(str_count_lines);
            mx_strdel(&str_count_lines);
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        stop = mx_read_line(&chr_num, 1, '\n', fd);
        if (!stop) {
            mx_strdel(&island1);
            mx_strdel(&island2);
            mx_strdel(&chr_num);
            free_connections(connections, size);
            free_core_memory(graph, names, size);
            close(fd);
            mx_printerr("error: line ");
            char *str_count_lines = mx_itoa(count_lines);
            mx_printerr(str_count_lines);
            mx_strdel(&str_count_lines);
            mx_printerr(" is not valid\n");
            exit(-1);
        }
        for (int i = 0; chr_num[i] != '\0'; i++) {
            if (chr_num[i] < '0' || chr_num[i] > '9') {
                mx_strdel(&island1);
                mx_strdel(&island2);
                mx_strdel(&chr_num);
                free_connections(connections, size);
                free_core_memory(graph, names, size);
                close(fd);
                mx_printerr("error: line ");
                char *str_count_lines = mx_itoa(count_lines);
                mx_printerr(str_count_lines);
                mx_strdel(&str_count_lines);
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }
        length = mx_atoi(chr_num);
        mx_strdel(&chr_num);
        bridges_sum += length;

        if (bridges_sum > INT_MAX) {
            mx_strdel(&island1);
            mx_strdel(&island2);
            free_core_memory(graph, names, size);
            free_connections(connections, size);
            close(fd);
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
        }

        const int idx1 = findOrAddIsland(names, &island_count, island1, size);
        const int idx2 = findOrAddIsland(names, &island_count, island2, size);
        mx_strdel(&island1);
        mx_strdel(&island2);
        if (idx1 == -1 || idx2 == -1) {
            free_core_memory(graph, names, size);
            free_connections(connections, size);
            close(fd);
            mx_printerr("error: invalid number of islands\n");
            exit(-1);
        }
        if (connections[idx1][idx2] || connections[idx2][idx1]) {
            free_connections(connections, size);
            free_core_memory(graph, names, size);
            close(fd);
            mx_printerr("error: duplicate bridges\n");
            exit(-1);
        }

        connections[idx1][idx2] = 1;
        connections[idx2][idx1] = 1;

        graph[idx1][idx2] = length;
        graph[idx2][idx1] = length;
    }
    free_connections(connections, size);
}


