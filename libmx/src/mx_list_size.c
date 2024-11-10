#include "libmx.h"

int mx_list_size(t_list *list) {
    if (list == NULL) {
        return 0;
    }
    int count = 1;
    t_list *temp = list;

    while(temp->next != NULL) {
        temp = temp->next;
        ++count;
    }
    
    return count;
}

