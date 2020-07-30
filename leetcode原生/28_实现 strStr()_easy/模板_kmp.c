void kmp_init(const char *s, int *prefix, size_t size) {
    prefix[0] = 0;
    for (size_t i = 1; i < size; ++i) {
        if (s[i] == s[prefix[i - 1]])
            prefix[i] = prefix[i - 1] + 1;
        else {
            int j = i - 1;
            while (prefix[j] > 0 && s[prefix[j]] != s[i])
                j = prefix[j] - 1;
            if (prefix[j] > 0)
                prefix[i] = prefix[j] + 1;
            else {
                prefix[i] = (s[i] == s[0]);
            }
        }
    }
}

int strStr(const char *src, const char *dest) {
    if (!dest || !src)
        return -1;
    if (!*dest)
        return 0;
    size_t size = strlen(dest);
    int *prefix = malloc(sizeof(int) * size);
    kmp_init(dest, prefix, size);
    size_t i, j;
    for (i = j = 0; src[i] && j < size; ++i) {
        if (dest[j] == src[i]) {
            ++j;
        }
        else if (j) {
            while (prefix[j - 1] > 0 && dest[prefix[j - 1]] != src[i])
                j = prefix[j - 1];
            if (prefix[j - 1] > 0) {
                j = prefix[j - 1] + 1;
            }
            else {
                j = (dest[0] == src[i]);
            }
        }
    }
    free(prefix);
    if (j < size)
        return -1;
    return i - size;
}