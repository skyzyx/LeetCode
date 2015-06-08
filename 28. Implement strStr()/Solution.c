// LeetCode #28: Implement strStr()

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(char* haystack, char* needle) {
    if (*needle == NULL)
        return 0;
        
    char *p, *q, *str;
    for (str = haystack; *str != NULL; str++) {
        for (p = str, q = needle; *p != NULL && *q != NULL && *p == *q; p++, q++)
            continue;
        if (*q == NULL)
            return str - haystack;
        if (*p == NULL)
            return -1;
    }
    return -1;
}