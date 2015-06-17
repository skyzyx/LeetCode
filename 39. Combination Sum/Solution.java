// LeetCode #39: Combination Sum

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (candidates == null || candidates.length == 0)
            return res;
            
        Arrays.sort(candidates);
        ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(candidates, 0, target, cur, res);
        return res;
    }
    
    private void dfs(int[] candidates, int start, int target, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (target == 0 && !res.contains(cur)) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            if (target >= candidates[i]) {
                cur.add(candidates[i]);
                dfs(candidates, i, target-candidates[i], cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
}