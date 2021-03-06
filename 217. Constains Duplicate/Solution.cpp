// LeetCode #217: Contains Duplicate

/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.size() < 2)
            return false;
            
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == 1)
                return true;
            else
                map[nums[i]] = 1;
        }
        return false;
    }
};

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
            
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i-1])
                return true;
                
        return false;
    }
};
*/