public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < numbers.length; i++) {
            if (!map.containsKey(numbers[i])) {
                map.put(target - numbers[i], i+1);
            } else {
                res[0] = map.get(numbers[i]);
                res[1] = i+1;
                return res;
            }
        }
        return res;
    }
}

// Add a comment.

