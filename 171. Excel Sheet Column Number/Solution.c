// LeetCode #171: Excel Sheet Column Number

/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

int titleToNumber(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        int curr = s[i] - 'A' + 1;
        res = res * 26 + curr;
    }
    return res;
}