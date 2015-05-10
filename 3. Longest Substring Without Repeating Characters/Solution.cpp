class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();
            
        int prev = 0;
        int maxLen = 0;
        bool visited[256] = {false};
        
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i]] == false) {
                visited[s[i]] = true;
            } else { 
                while (s[i] != s[prev]) {
                    visited[s[prev]] = false;
                    prev++;
                }
                prev++;
            }
            maxLen = max(maxLen, i - prev + 1);
        }
        return maxLen;
        
    }
};