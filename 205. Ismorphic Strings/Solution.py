class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        if len(s) != len(t):
            return False
            
        sdict = {}
        tdict = {}
        
        for i in xrange(len(s)):
            if sdict.has_key(s[i]):
                if sdict[s[i]] != t[i]:
                    return False
                    
            if tdict.has_key(t[i]):
                if tdict[t[i]] != s[i]:
                    return False
                    
            sdict[s[i]] = t[i]
            tdict[t[i]] = s[i]
        
        return True