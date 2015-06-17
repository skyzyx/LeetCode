// LeetCode #40: Combination Sum II

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
          
        Arrays.sort(num);
        
        ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(num, 0, target, cur, res);
        return res;
    }
    
    private void dfs(int[] num, int start, int target, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (target == 0 && !res.contains(cur))
            res.add(new ArrayList<Integer>(cur));
        
        for (int i = start; i < num.length; i++) {
            if (target >= num[i]) {
                cur.add(num[i]);
                dfs(num, i+1, target-num[i], cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
}