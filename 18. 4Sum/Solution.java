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

public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        List res = new ArrayList();
        //if (num == null || num.length < 4)
            //return res;
            
        Arrays.sort(num);
        for (int i = 0; i < num.length; i++) {
            for (int j = i+1; j < num.length; j++) {
                int l = j+1;
                int r = num.length - 1;
                int remain = target - num[i] - num[j];
                
                while (l < r) {
                    if (remain == num[l] + num[r]) {
                        List<Integer> tmp = new ArrayList<Integer>();
                        tmp.add(num[i]);
                        tmp.add(num[j]);
                        tmp.add(num[l]);
                        tmp.add(num[r]);
                        
                        if (!res.contains(tmp))
                            res.add(tmp);
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
}