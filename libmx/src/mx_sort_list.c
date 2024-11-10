#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b)) {
    if (list == NULL || list->next == NULL) {
        return list; // Already sorted or empty list
    }
    bool swapped = true;
    t_list *temp;

    while (swapped) {
        swapped = false;
        t_list *current = list;
        t_list *prev = NULL;

        while (current->next != NULL) {
            if (cmp(current->data, current->next->data)) {
                temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev != NULL) {
                    prev->next = temp;
                } else {
                    list = temp;
                }
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    }
    return list;
}

