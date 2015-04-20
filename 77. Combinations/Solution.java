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