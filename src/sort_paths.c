#include "../inc/pathfinder.h"

int compare_paths(t_path *path_a, t_path *path_b) {
    if (path_a->start == path_b->start && path_a->goal == path_b->goal) {
        int i = 0;
        while (i < path_a->length && i < path_b->length) {
            if (path_a->route[i] != path_b->route[i]) {
                return path_a->route[i] - path_b->route[i];
            }
            i++;
        }
        return path_a->length - path_b->length;
    }
    return 0;
}

void bubble_sort_paths(t_path *paths, int path_count) {
    for (int i = 0; i < path_count - 1; i++) {
        for (int j = 0; j < path_count - i - 1; j++) {
            if (compare_paths(&paths[j], &paths[j + 1]) > 0) {
                t_path temp = paths[j];
                paths[j] = paths[j + 1];
                paths[j + 1] = temp;
            }
        }
    }
}

