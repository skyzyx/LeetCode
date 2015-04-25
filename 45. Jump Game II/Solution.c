int jump(int* nums, int numsSize) {
    int currmax = 0;
    int lastmax = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (i > lastmax) {
            lastmax = currmax;
            count++;
        }
        
        if (i + nums[i] > currmax)
            currmax = i + nums[i];
    }
    return count;
}