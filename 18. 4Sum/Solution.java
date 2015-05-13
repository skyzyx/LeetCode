public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        List res = new ArrayList();
        //if (num == null || num.length < 4)
            //return res;
            
        Arrays.sort(num);
        for (int i = 0; i < num.length; i++) {
            for (int j = i+1; j < num.length; j++) {
                int l = j+1;
                int r = num.length - 1;
                int remain = target - num[i] - num[j];
                
                while (l < r) {
                    if (remain == num[l] + num[r]) {
                        List<Integer> tmp = new ArrayList<Integer>();
                        tmp.add(num[i]);
                        tmp.add(num[j]);
                        tmp.add(num[l]);
                        tmp.add(num[r]);
                        
                        if (!res.contains(tmp))
                            res.add(tmp);
                        l++;
                        r--;
                    } else if (remain > num[l] + num[r]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
        
    }
}