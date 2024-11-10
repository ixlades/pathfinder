int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n > 0 && *s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        n--;
    }
    if (n > 0) {
        return (*s1 - *s2);
    }
    return 0;
}

