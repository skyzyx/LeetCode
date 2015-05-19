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