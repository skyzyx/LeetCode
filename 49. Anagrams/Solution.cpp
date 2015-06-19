// LeetCode #49: Anagrams

/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> res;
        if (strs.size() < 2)
            return res;
            
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (map.find(s) == map.end()) {
                vector<string> foo;
                foo.push_back(strs[i]);
                map[s] = foo;
            } else {
                map[s].push_back(strs[i]);
            }
        }
        
        for(unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++) {
            if((*it).second.size() > 1) {
                res.insert(res.end(), (*it).second.begin(), (*it).second.end());
            }
        }
        return res;
        
    }
};