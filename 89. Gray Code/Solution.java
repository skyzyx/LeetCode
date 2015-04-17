public class Solution {
    public List<Integer> grayCode(int n) {
        if (n < 0)
            return null;
            
        List<Integer> res = new ArrayList<Integer>();
        if (n == 0) {
            res.add(0);
            return res;
        }
        
        List<Integer> preRes = grayCode(n-1);
        res.addAll(preRes); // error: no suitable method found for add(List<Integer>)
        
        for (int i = preRes.size() - 1; i >= 0; i--)
            res.add(preRes.get(i) + (int)Math.pow(2, n - 1)); // no suitable method found for add(double)
            
        return res;
    }
}