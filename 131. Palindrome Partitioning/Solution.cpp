// LeetCode #131: Palindrome Partitioning

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0)
            return res;
            
        vector<string> cur;
        dfs(s, cur, res);
        return res;
    }
    
private:
    void dfs(string s, vector<string> &cur, vector<vector<string>> &res) {
        if (s.size() == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                dfs(s.substr(i), cur, res);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;
            
        int i = 0; 
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};