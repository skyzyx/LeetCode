class Solution:
    # @param {string} haystack
    # @param {string} needle
    # @return {integer}
    def strStr(self, haystack, needle):
        hlen = len(haystack)
        nlen = len(needle)
        
        i = 0
        while i + nlen <= hlen:
            if haystack[i: i+nlen] == needle:
                return i
            i += 1
        return -1