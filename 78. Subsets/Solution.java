public class Solution {
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        if (S == null)
            return null;
            
        Arrays.sort(S);
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        
        /*
        Input:	[0]
        Output:	[]
        Expected:	[[],[0]]
        */
        res.add(new ArrayList<Integer>());
        
        for (int i = 0; i < S.length; i++) {
            int size = res.size();
            for (int j = 0; j < size; j++) {
                ArrayList<Integer> tmp = new ArrayList<Integer>(res.get(j));
                // tmp.add(res.get(j)); no suitable method found for add(Object)
                tmp.add(S[i]);
                res.add(tmp);
            }
        }
        return res;
    }
}