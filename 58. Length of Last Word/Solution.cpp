class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
            
        int len = s.size() - 1;
        while (len >= 0 && s[len] == ' ')
            len--;
            
        int count = 0;
        while (len >= 0 && s[len] != ' ') {
            count++;
            len--;
        }
        
        return count;
    }
};