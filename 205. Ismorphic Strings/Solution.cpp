class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
            
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        
        for (int i = 0; i < s.size(); i++) {
            if (smap.find(s[i]) != smap.end())
                if (smap[s[i]] != t[i])
                    return false;
                    
            if (tmap.find(t[i]) != tmap.end())
                if (tmap[t[i]] != s[i])
                    return false;
                    
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        return true;
    }
};