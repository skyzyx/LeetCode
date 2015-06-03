// LeetCode #134: Gas Station

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

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