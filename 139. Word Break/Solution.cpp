// LeetCode #139: Word Break

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0)
            return true;
            
        int m = s.size();
        int isValid[m+1] = {false};
        isValid[0] = true;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (isValid[j] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) { // NOT s.substr(j, i+1)
                    isValid[i+1] = true;
                    break;
                }
            }
        }
        return isValid[m];
    }
};

/*
class Solution { // Time Limit Exceeded
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0)
            return true;
            
        for (int i = 0; i <= s.size(); i++) {
            string firstWord = s.substr(0, i);
            if (wordDict.find(firstWord) != wordDict.end())
                wordBreak(s.substr(i), wordDict);
        }
        
        return false;
    }
};
*/