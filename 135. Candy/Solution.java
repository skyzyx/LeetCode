public class Solution {
    public int candy(int[] ratings) {
        if (ratings == null || ratings.length == 0)
            return 0;
            
        int[] res = new int[ratings.length];
        Arrays.fill(res, 1);
        
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i-1])
                res[i] = res[i-1]+1;
        }
        
        int candyNums = 0;
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && res[i] <= res[i+1])
                res[i] = res[i+1]+1;
                
            candyNums += res[i];
        }
        candyNums += res[res.length - 1];
        return candyNums;
    }
}