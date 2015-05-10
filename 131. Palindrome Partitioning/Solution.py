class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        res = []
        if s == None or len(s) == 0:
            return res
            
        cur = []
        self.dfs(s, cur, res)
        return res
        
    def dfs(self, s, cur, res):
        if len(s) == 0:
            res.append(list(cur))
            return
        
        size = len(s)
        for i in xrange(1, size + 1):
            sub = s[0:i]
            if self.isPalindrome(sub) == True:
                cur.append(sub)
                self.dfs(s[i:], cur, res)
                cur.pop()
                
    def isPalindrome(self, s):
        if s == None or len(s) <= 1:
            return True
            
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
            