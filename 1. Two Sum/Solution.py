class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        mydic = {}
        res = [-1] * 2
        for i in xrange(len(nums)):
            if nums[i] not in mydic:
                mydic[target - nums[i]] = i+1
            else:
                res[0] = mydic[nums[i]]
                res[1] = i+1
                break
        return res