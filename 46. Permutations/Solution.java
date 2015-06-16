// LeetCode #46: Permutations

/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

// Permutations of a word, http://www.ardendertat.com/2011/10/28/programming-interview-questions-11-all-permutations-of-string/

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
            if (!cur.contains(num[i])) {
                cur.add(num[i]);
                dfs(num, cur, res);
                cur.remove(cur.size() - 1);
            }
        }
    }
}

/* 
Input:  [0,1]
Output: [[0,1]]
Expected:   [[0,1],[1,0]]

public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
            
        Arrays.sort(num);
        ArrayList<Integer> cur = new ArrayList<Integer>();
        dfs(0, num, cur, res);
        return res;
    }
    
    private void dfs(int start, int[] num, ArrayList<Integer> cur, ArrayList<ArrayList<Integer>> res) {
        if (cur.size() == num.length) {
            res.add(new ArrayList<Integer>(cur));
            return;
        }
        
        for (int i = start; i < num.length; i++) {
            //if (cur.contains(num[i]))
                //continue;
                
            cur.add(num[i]);
            dfs(i+1, num, cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}
*/