#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) return -1;
    int gg = 0;

    if (left < right) {
        const char *pivot = arr[(left + right) / 2];
        const int pivot_length = mx_strlen(pivot);
        int i = left;
        int j = right;

        while (i <= j) {
            while (mx_strlen(arr[i]) < pivot_length) i++;

            while (mx_strlen(arr[j]) > pivot_length) j--;

            if (i <= j) {
                if (i != j) {
                    swap_str(&arr[i], &arr[j]);
                    gg++;
                }
                i++;
                j--;
            }
        }
        mx_quicksort(arr, i, right);
        mx_quicksort(arr, left, j);
    }
    return gg;
}

