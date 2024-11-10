char *mx_strncpy(char *dst, const char *src, int len) {
    char *pdst = dst;
    
    for (int i = 0; i < len; ++i) {
        if (*src == '\0') {
            *dst = *src;
            ++dst;
        } else {
            *dst = *src;
            ++dst;
            ++src;
        }
    }
    return pdst;
}

