class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def longestConsecutive(self, nums):
        dic = {num: False for num in nums}
        maxLen = 0
        
        for num in nums:
            if dic[num] == False:
                count = 1
                left = num - 1
                right = num + 1
                
                while left in dic and dic[left] == False: # Without "left in dic", an error occured, KeyError: -1
                    dic[left] = True # Means visited.
                    count += 1
                    left -= 1
                    
                while right in dic and dic[right] == False:
                    dic[right] = True
                    count += 1
                    right += 1
                
                maxLen = max(maxLen, count)
                
        return maxLen
                    