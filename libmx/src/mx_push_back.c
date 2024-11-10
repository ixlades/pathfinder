#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *newNode = mx_create_node(data);

    if (*list == NULL) {
        *list = newNode;
    } else {
        t_list *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

