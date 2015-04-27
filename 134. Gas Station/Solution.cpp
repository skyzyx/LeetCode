class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0 || cost.size() == 0)
            return -1;
            
        int startPoint = 0;
        int curGas = 0;
        int totalGas = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            
            if (curGas < 0) {
                curGas = 0;
                startPoint = i+1;
            }
        }
        
        return totalGas >= 0? startPoint: -1;
    }
};