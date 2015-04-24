public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List res = new ArrayList();
        if (numRows <= 0)
            return res;
            
        List<Integer> cur = new ArrayList<Integer>();
        cur.add(1);
        res.add(cur);
        
        for (int i = 0; i < numRows - 1; i++) {
            List<Integer> tmp = new ArrayList<Integer>(cur);
            
            for (int j = 1; j < cur.size(); j++) {
                tmp.set(j, cur.get(j) + cur.get(j-1));
            }
            tmp.add(1);
            res.add(tmp);

            cur = new ArrayList<Integer>(tmp);
        }
        return res;
    }
}