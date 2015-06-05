// LeetCode #168: Excel Sheet Column Title

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n > 0) {
            n--;
            char letter = (char)(n % 26 + 'A');
            res.insert(res.begin(), letter);
            n /= 26;
        }
        return res;
    }
};