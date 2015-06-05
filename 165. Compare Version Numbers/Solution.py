# LeetCode #165: Compare Version Numbers

'''
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
'''

class Solution:
    def compareVersion(self, version1, version2):
        i = 0
        j = 0
        while i < len(version1) or j < len(version2):
            data1 = 0
            data2 = 0
            while i < len(version1) and version1[i] != '.':
                data1 = data1 * 10 + int(version1[i])
                i += 1
                
            while j < len(version2) and version2[j] != '.':
                data2 = data2 * 10 + int(version2[j])
                j += 1
                
            if data1 > data2:
                return 1
            if data1 < data2:
                return -1
                
            i += 1
            j += 1
                
        return 0

'''
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        data1 = version1.split(".")
        data2 = version2.split(".")
        
        maxLen = max(len(data1), len(data2))
        for i in range(maxLen):
            a = int(data1[i]) if (i < len(data1)) else 0
            b = int(data2[i]) if (i < len(data2)) else 0
            
            if a > b:
                return 1
            elif a < b:
                return -1
        
        return 0
'''