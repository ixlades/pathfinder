#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    buf_size = 1;
    char *max_size_buff = mx_strnew(buf_size);
    ssize_t full_size = read(fd, max_size_buff, buf_size);

    if (full_size == -1) return -2;
    if (full_size == 0) {
        mx_strdel(&max_size_buff);
        return -1;
    }
    if (*max_size_buff == delim) {
        mx_strdel(&max_size_buff);
        return 0;
    }

    char c = '\0';
    while (c != delim) {
        ssize_t temp;
        temp = read(fd, &c, sizeof(char));

        if (temp == -1) return -2;
        if (temp == 0) {
            *lineptr = mx_strdup(max_size_buff);
            mx_strdel(&max_size_buff);
            return full_size;
        }
        full_size += temp;
        if (c == delim) break;

        char *xtra_str = mx_realloc(max_size_buff, full_size);
        max_size_buff = mx_strdup(xtra_str);
        mx_strdel(&xtra_str);
        if (max_size_buff == NULL) return -2;
        max_size_buff[full_size -1] = c;

    }
    int size_without_delim = return_size_of_word(max_size_buff, delim);

    *lineptr = mx_strndup(max_size_buff, size_without_delim);
    mx_strdel(&max_size_buff);

    return size_without_delim;
}
