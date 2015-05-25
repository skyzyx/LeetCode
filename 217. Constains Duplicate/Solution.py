class Solution:
    def containsDuplicate(self, nums):
        if nums == None or len(nums) < 2:
            return False
            
        mydict = {}
        for i in xrange(len(nums)):
            if mydict.has_key(nums[i]): # nums[i] in mydict # NOT mydict[nums[i]] == 1
                return True
            else:
                mydict[nums[i]] = 1
        return False

'''
class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        if len(nums) < 2:
            return False
            
        nums.sort()
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1]:
                return True
                
        return False
'''