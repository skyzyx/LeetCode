// LeetCode #14: Longest Common Prefix

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
            
        for (int i = 0; i < strs[0].size(); i++) {
            char letter = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || letter != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
        
    }
};