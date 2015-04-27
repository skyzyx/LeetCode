int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    if (gas == NULL || cost == NULL || gasSize == 0 || costSize == 0)
        return -1;
        
    int startPoint = 0;
    int curGas = 0;
    int totalGas = 0;
    
    for (int i = 0; i < gasSize; i++) {
        curGas += gas[i] - cost[i];
        totalGas += gas[i] - cost[i];
        
        if (curGas < 0) {
            curGas = 0;
            startPoint = i + 1;
        }
    }
    
    return totalGas >= 0? startPoint: -1;
}