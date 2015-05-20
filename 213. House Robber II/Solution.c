int max(int a, int b) {
    return a >= b? a: b;
}

int houseRob(int* nums, int from, int to) {
    int even = 0;
    int odd = 0;
    for (int i = from; i <= to; i++) {
        if (i % 2 == 0)
            even = max(even + nums[i], odd);
        else
            odd = max(odd + nums[i], even);
    }
    return max(even, odd);
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return max(nums[0], nums[1]);
        
    return max(houseRob(nums, 0, numsSize - 2), houseRob(nums, 1, numsSize - 1));
}