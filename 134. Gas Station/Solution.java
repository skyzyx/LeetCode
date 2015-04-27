public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas == null || cost == null || gas.length == 0 || cost.length == 0)
            return -1;
            
        int curGas = 0;
        int totalGas = 0;
        int startPoint = 0;
        
        for (int i = 0; i < gas.length; i++) {
            curGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            
            if (curGas < 0) {
                curGas = 0;
                startPoint = i+1;
            }
        }
        
        return totalGas >= 0? startPoint: -1;
    }
}