# LeetCode #49: Anagrams

'''
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

Update (2015-08-09):
The signature of the function had been updated to return list<list<string>> instead of 
list<string>, as suggested here. If you still see your function signature return a 
list<string>, please click the reload button  to reset your code definition.
'''

class Solution:
    # @param {string[]} strs
    # @return {string[][]}
    def groupAnagrams(self, strs):
        res = []
        dic = {}
        for word in strs:
            sword = ''.join(sorted(word))
            dic[sword] = [word] if sword not in dic else dic[sword] + [word]
            
        for key in dic:
            res.append(sorted(dic[key]))
            
        return res

'''
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
'''       