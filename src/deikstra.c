#include "../inc/pathfinder.h"


void add_path(const t_recovery_state* state, const t_graph_context* graph_context) {
    int* saved_path = malloc((state->path_length + 2) * sizeof(int));
    if (!saved_path) return;

    for (int i = 0; i <= state->path_length; i++) {
        saved_path[i] = state->path[state->path_length - i];
    }
    saved_path[state->path_length + 1] = -1;

    int total_distance = 0;
    for (int i = 0; i < state->path_length; i++) {
        total_distance += graph_context->graph[saved_path[i]][saved_path[i + 1]];
    }

    if (total_distance == graph_context->distance[state->goal]) {
        (*state->path_count)++;
        t_path* new_paths = mx_realloc(*state->collected_paths, (*state->path_count) * sizeof(t_path));
        if (!new_paths) {
            free(saved_path);
            return;
        }
        *state->collected_paths = new_paths;

        t_path* new_path = &(*state->collected_paths)[*state->path_count - 1];
        new_path->start = state->start;
        new_path->goal = state->goal;
        new_path->route = saved_path;
        new_path->length = state->path_length + 1;
    } else {
        free(saved_path);
    }
}

void recover_all_paths(const t_recovery_state* state, const t_graph_context* graph_context, int current_goal) {
    state->path[state->path_length] = current_goal;

    if (current_goal == state->start) {
        add_path(state, graph_context);
        return;
    }

    for (int i = 0; i < graph_context->prev_count[current_goal]; i++) {
        int prev_node = graph_context->previous[current_goal][i];
        if (state->path_length > 0 && prev_node == state->path[state->path_length - 1]) continue;

        t_recovery_state new_state = *state;
        new_state.path_length++;
        recover_all_paths(&new_state, graph_context, prev_node);
    }
}

t_path* deikstra(int num_islands, int** graph, int start, int* path_count) {
    t_graph_context graph_context;
    graph_context.graph = graph;
    graph_context.num_islands = num_islands;
    graph_context.distance = malloc(num_islands * sizeof(int));
    graph_context.previous = malloc(num_islands * sizeof(int*));
    graph_context.prev_count = malloc(num_islands * sizeof(int));

    bool* visited = malloc(num_islands * sizeof(bool));

    for (int i = 0; i < num_islands; i++) {
        graph_context.distance[i] = INT_MAX;
        graph_context.previous[i] = malloc(num_islands * sizeof(int));
        graph_context.prev_count[i] = 0;
        visited[i] = false;
    }
    graph_context.distance[start] = 0;

    for (int i = 0; i < num_islands - 1; i++) {
        int min_dist = INT_MAX, current_node = -1;
        for (int j = 0; j < num_islands; j++) {
            if (!visited[j] && graph_context.distance[j] < min_dist) {
                min_dist = graph_context.distance[j];
                current_node = j;
            }
        }

        if (current_node == -1) break;
        visited[current_node] = true;

        for (int neighbor_node = 0; neighbor_node < num_islands; neighbor_node++) {
            int weight = graph[current_node][neighbor_node];
            if (weight != -1 && !visited[neighbor_node] && graph_context.distance[current_node] + weight <= graph_context.distance[neighbor_node]) {
                if (graph_context.distance[current_node] + weight < graph_context.distance[neighbor_node]) {
                    graph_context.distance[neighbor_node] = graph_context.distance[current_node] + weight;
                    graph_context.previous[neighbor_node][0] = current_node;
                    graph_context.prev_count[neighbor_node] = 1;
                } else if (graph_context.distance[current_node] + weight == graph_context.distance[neighbor_node]) {
                    graph_context.previous[neighbor_node][graph_context.prev_count[neighbor_node]++] = current_node;
                }
            }
        }
    }

    t_path* collected_paths = NULL;
    *path_count = 0;

    for (int dest = 0; dest < num_islands; dest++) {
        if (dest != start && graph_context.distance[dest] != INT_MAX) {
            int* path = malloc(num_islands * sizeof(int));
            t_recovery_state state = {start, dest, path, 0, &collected_paths, path_count};
            recover_all_paths(&state, &graph_context, dest);
            free(path);
        }
    }

    for (int i = 0; i < num_islands; i++) free(graph_context.previous[i]);
    free(graph_context.previous);
    free(graph_context.prev_count);
    free(graph_context.distance);
    free(visited);

    return collected_paths;
}


