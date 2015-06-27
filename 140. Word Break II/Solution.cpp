// LeetCode #140: Word Break II

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.size() == 0 || isBreak(s, wordDict) == false)
            return res;
        
        dfs("", res, s, wordDict);
        return res;
    }
    
private:
    bool isBreak(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0)
            return true;
            
        int m = s.size();
        bool dp[m+1] = {false};
        dp[0] = true;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] == true && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[m];
    }
    
    void dfs(string t, vector<string>& res, string s, unordered_set<string>& wordDict) {
        if (s.size() == 0) {
            res.push_back(t);
            return;
        }
        
        for (int i = 0; i <= s.length(); i++) {
            string word = s.substr(0, i);
            if (wordDict.find(word) != wordDict.end()) {
                string curr = t.size() == 0? word: t + " " + word;
                dfs(curr, res, s.substr(i), wordDict);
            }
        }
    }
};