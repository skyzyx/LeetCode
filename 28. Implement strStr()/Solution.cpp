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