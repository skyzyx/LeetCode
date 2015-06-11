// LeetCode #77: Combinations

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (k <= 0)
            return res;
        ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(1, n, k, cur, res);
        return res;
    }
    
    private void dfs(int start, int n, int k, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (cur.size() == k) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = start; i <= n; i++) {
            cur.add(i);
            dfs(i+1, n, k, cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}