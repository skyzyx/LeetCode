class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[][]}
    def fourSum(self, nums, target):
        res = []
        nums.sort()
        
        for i in xrange(0, len(nums)):
            for j in xrange(i+1, len(nums)):
                l = j + 1
                r = len(nums) - 1
                remain = target - nums[i] - nums[j]
                
                while l < r:
                    if remain == nums[l] + nums[r]:
                        cur = []
                        cur.append(nums[i])
                        cur.append(nums[j])
                        cur.append(nums[l])
                        cur.append(nums[r])
                    
                        if cur not in res:
                            res.append(cur)
                        
                        l += 1
                        r -= 1
                    elif remain > nums[l] + nums[r]:
                        l += 1
                    else:
                        r -= 1
        return res