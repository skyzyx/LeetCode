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