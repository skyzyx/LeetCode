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