int memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1 = s1;
    unsigned char *str2 = s2;
    int i = 0;

    while (i < n)
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return 0;
}