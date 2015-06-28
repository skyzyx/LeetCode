// LeetCode #164: Maximum Gap

/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        int maxGap = 0;
        sort(num.begin(), num.end());
        
        for (int i = 1; i < num.size(); i++)
            maxGap = max(maxGap, num[i] - num[i-1]);
        return maxGap;
    }
};