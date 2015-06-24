// LeetCode #216: Combination Sum III

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List res = new ArrayList();
        if (k <= 0)
            return res;
            
        List<Integer> cur = new ArrayList<Integer>();
        dfs(k, 1, n, cur, res);
        return res;
    }
    
    private void dfs(int k, int start, int target, List<Integer> cur, List<List<Integer>> res) {
        if (target == 0 && cur.size() == k) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = start; i <= 9; i++) {// NOT i <= n
            if (target >= i) {
                cur.add(i);
                dfs(k, i+1, target - i, cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
}