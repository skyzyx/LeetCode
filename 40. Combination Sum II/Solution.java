public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
          
        Arrays.sort(num);
        
        ArrayList<Integer> cur = new ArrayList<Integer>();
        recursiveCombination(num, 0, target, cur, res);
        return res;
    }
    
    private void recursiveCombination(int[] num, int start, int target, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (target == 0) {
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur);
            if (!res.contains(tmp))
                res.add(tmp);
        }
        
        for (int i = start; i < num.length; i++) {
            if (num[i] > target)
                continue;
                
            cur.add(num[i]);
            recursiveCombination(num, i+1, target-num[i], cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}