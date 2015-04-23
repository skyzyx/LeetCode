class Solution:
    # @param {string[]} strs
    # @return {string[]}
    def anagrams(self, strs):
        res = []
        dic = {}
        for word in strs:
            sword = ''.join(sorted(word)) # sword = sorted(word) TypeError: unhashable type: 'list'
            dic[sword] = [word] if sword not in dic else dic[sword] + [word]
            
        for elem in dic:
            if len(dic[elem]) > 1:
                res = res + dic[elem]
                
        return res
            
        