#include "../inc/pathfinder.h"

int return_island_num(const int fd) {
    char *str_num;
    int is_empty = mx_read_line(&str_num, 1, '\n', fd);

    if (is_empty == -1) {
        mx_strdel(&str_num);
        return is_empty;
    }
    for (int i = 0; str_num[i] != '\0'; i++) {
        if (str_num[i] < '0' || str_num[i] > '9') {
        	close(fd);
            mx_strdel(&str_num);
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
    }

    const int island_num = mx_atoi(str_num);

    mx_strdel(&str_num);
    return island_num;
}


void pathfinder(const char *filename) {
    const int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(-1);
    }
    const int island_num = return_island_num(fd);

    if (island_num == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        close(fd);
        exit(-1);
    }
    int **graph = graph_init(island_num);
    char **names = malloc(sizeof(char *) * island_num);


    graph_fill(fd, graph, names, island_num);
    close(fd);
    bool **visited = malloc(sizeof(bool *) * island_num);

    for (int i = 0; i < island_num; ++i) {
        visited[i] = (bool *)malloc(island_num * sizeof(bool));
        for (int j = 0; j < island_num; ++j) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < island_num; ++i) {
        int path_count = 0;
        t_path *current_path = deikstra(island_num, graph, i, &path_count);
        bubble_sort_paths(current_path, path_count);
        for (int k = i; k < path_count; k++) {
            int src = i;
            int dest = current_path[k].goal;

            if (visited[src][dest] || visited[dest][src]) {
                if (!k) continue;
                if (current_path[k - 1].goal != dest || current_path[k - 1].start != src) continue;
            }
            visited[src][dest] = true;
            visited[dest][src] = true;

            print_path_block(graph, names, current_path[k].route, current_path[k].goal);
        }

        for (int k = 0; k < path_count; k++) free(current_path[k].route);
        free(current_path);
    }

    free_core_memory(graph, names, island_num);

    for (int i = 0; i < island_num; ++i) {
        free(visited[i]);
    }
    free(visited);
}

