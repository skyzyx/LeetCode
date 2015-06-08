// LeetCode #28: Implement strStr()

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        
        for (int i = 0; i + nlen <= hlen; i++) {
            string tmp = haystack.substr(i, nlen); // str.substr(pos, len)
            if (tmp == needle) // !tmp.compare(needle)
                return i;
        }
        return -1;
    }
};