public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
            
        Arrays.sort(num);
        ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(num, cur, res);
        return res;
    }
    
    private void dfs(int[] num, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (cur.size() == num.length) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = 0; i < num.length; i++) {
            if (cur.contains(num[i]))
                continue;
                
            cur.add(num[i]);
            dfs(num, cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}