class Solution:
    # @param {integer[]} numbers
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, numbers, target):
        res = [-1, -1]
        if len(numbers) < 2:
            return res
            
        i = 0
        j = len(numbers) - 1
        while i < j:
            if numbers[i] + numbers[j] == target:
                res[0] = i+1
                res[1] = j+1
                return res
            elif numbers[i] + numbers[j] > target:
                j -= 1
            else:
                i += 1
        return res