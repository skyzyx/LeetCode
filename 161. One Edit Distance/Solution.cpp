class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        
        if (slen > tlen)
            return isOneEditDistance(t, s);
            
        if (tlen - slen > 1)
            return false;
            
        if (tlen == slen) {
            int diff = 0;
            for (int i = 0; i < tlen && diff < 2; i++)
                if (s[i] != t[i])
                    diff++;
                    
            return diff == 1;
        }
        
        int i = 0; 
        for (; i < slen; i++) {
            if (s[i] != t[i])
                break;
        }
        
        t.erase(i, 1);
        return s == t;
    }
};