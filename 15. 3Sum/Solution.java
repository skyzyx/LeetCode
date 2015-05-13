public class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (num == null || num.length < 3)
            return res;
        
        Arrays.sort(num);
        for (int i = 0; i < num.length; i++) {
            int target = 0 - num[i];
            int l = i + 1;
            int r = num.length - 1;
            while (l < r) {
                if (num[l] + num[r] == target) {
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(num[i]);
                    temp.add(num[l]);
                    temp.add(num[r]);
                    if (!res.contains(temp))
                        res.add(temp);
                    l++;
                    r--;
                } else if (num[l] + num[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
}