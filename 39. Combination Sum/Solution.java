public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (candidates == null || candidates.length == 0)
            return res;
            
        Arrays.sort(candidates);
        ArrayList<Integer> cur = new ArrayList<Integer>();
        recursiveCombination(candidates, 0, target, cur, res);
        return res;
    }
    
    private void recursiveCombination(int[] candidates, int start, int target, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (target == 0) {
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur);
            res.add(tmp);
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            if (target >= candidates[i]) {
                cur.add(candidates[i]);
                recursiveCombination(candidates, i, target-candidates[i], cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
}