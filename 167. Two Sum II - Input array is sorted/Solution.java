public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {-1, -1};
        if (numbers.length < 2)
            return res;
        
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                res[0] = i+1;
                res[1] = j+1;
                return res;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }
}