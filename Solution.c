bool canJump(int* nums, int numsSize) {
    int maxdist = 0;
    for (int i = 0; i <= maxdist && i < numsSize; i++) {
        if (maxdist < i + nums[i])
            maxdist = i + nums[i];
            
        if (maxdist >= numsSize - 1)
            return true;
    }
    return false;
}