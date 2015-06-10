// LeetCode #18: 4Sum

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        //if (num.size() < 4)
            //return res;
            
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i++) {
            for (int j = i+1; j < num.size(); j++) {
                int l = j+1;
                int r = num.size() - 1;
                int remain = target - num[i] - num[j];
                
                while (l < r) {
                    if (remain == num[l] + num[r]) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        
                        if (find(res.begin(), res.end(), tmp) == res.end())
                            res.push_back(tmp);
                        
                        l++;
                        r--;
                    } else if (remain > num[l] + num[r]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};