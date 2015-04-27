class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        if n < 1:
            return "";
            
        res = "1"
        for i in xrange(1, n):
            tmp = ""
            count = 1
            for j in range(1, len(res)):
                if res[j] == res[j-1]:
                    count += 1
                else:
                    tmp += str(count) + res[j-1]
                    count = 1
            
            tmp += str(count) + res[len(res) - 1]
            res = tmp
            
        return res