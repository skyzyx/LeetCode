// LeetCode #47: Permutations II

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
            
        Arrays.sort(num); // http://fisherlei.blogspot.com/2012/12/leetcode-permutations-ii.html
        
        ArrayList<Integer> cur = new ArrayList<Integer>();
        boolean[] visited = new boolean[num.length];
        dfs(num, visited, cur, res);
        return res;
    }
    
    private void dfs(int[] num, boolean[] visited, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (cur.size() == num.length) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = 0; i < num.length; i++) {
            if (visited[i] == true || (i > 0 && num[i] == num[i-1] && !visited[i-1]))
                continue;
                
            visited[i] = true;
            cur.add(num[i]);
            dfs(num, visited, cur, res);
            cur.remove(cur.size() - 1);
            visited[i] = false;
        }
    }
}