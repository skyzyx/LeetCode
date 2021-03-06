// LeetCode #90: Subsets II

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
            
        Arrays.sort(num);
        res.add(new ArrayList<Integer>());
        
        for (int i = 0; i < num.length; i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                ArrayList<Integer> cur = new ArrayList<Integer>(res.get(j));
                cur.add(num[i]);
                if (!res.contains(cur))
                    res.add(cur);
            }
        }
        return res;
    }
}

/*
public class Solution {
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (num == null || num.length == 0)
            return res;
        
        Arrays.sort(num);
        int size = 1 << num.length;
        for (int i = 0; i < size; i++) {
            int data = i;
            int index = 0;
            ArrayList<Integer> temp = new ArrayList<Integer>();
            while (data > 0) {
                if ((data & 1) == 1)
                    temp.add(num[index]);
                index++;
                data >>= 1;
            }
            
            if (!res.contains(temp))
                res.add(temp);
        }
        return res;
    }
}
*/