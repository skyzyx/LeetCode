class Solution:
    # @param {string} s
    # @return {string[]}
    def restoreIpAddresses(self, s):
        if s == None or len(s) < 4 or len(s) > 12:
            return []
            
        res = []
        self.dfs(s, "", res, 0);
        return res
        
    def dfs(self, s, tmp, res, count):
        if count == 3 and self.isValid(s):
            res.append(tmp + s)
            return
        
        i = 1
        while i < 4 and i < len(s):
            substr = s[0:i]
            if self.isValid(substr):
                self.dfs(s[i:], tmp + substr + ".", res, count + 1)
            i += 1
    
    def isValid(self, s):
        if s == None or len(s) < 0:
            return False
        if s[0] == '0':
            return s == "0"
        return int(s) > 0 and int(s) <= 255
            
            
        