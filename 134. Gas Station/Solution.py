class Solution:
    # @param {integer[]} gas
    # @param {integer[]} cost
    # @return {integer}
    def canCompleteCircuit(self, gas, cost):
        if len(gas) == 0 or len(cost) == 0:
            return -1
            
        startPoint = 0
        curGas = 0
        totalGas = 0
        
        for i in xrange(len(gas)):
            curGas += gas[i] - cost[i]
            totalGas += gas[i] - cost[i]
            
            if curGas < 0:
                curGas = 0
                startPoint = i+1
                
        return startPoint if totalGas >= 0 else -1