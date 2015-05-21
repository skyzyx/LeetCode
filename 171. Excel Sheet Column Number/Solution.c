int titleToNumber(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        int curr = s[i] - 'A' + 1;
        res = res * 26 + curr;
    }
    return res;
}