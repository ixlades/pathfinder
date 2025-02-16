#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ++counter;
            }
        }
    }
    return counter;
}

