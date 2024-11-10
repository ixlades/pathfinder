char *mx_strcpy(char *dst, const char *src) {
    int i = 0;

    while (*src != '\0') {
        dst[i] = *src;
        ++src;
        ++i;
    }

    dst[i] = '\0';
    return dst;
}

