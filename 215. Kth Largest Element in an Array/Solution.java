// LeetCode #215: Kth Largest Element in an Array

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

public class Solution {
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return -1;
            
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}

/*
public class Solution { // Minheap, O(k) space, O(n) time.
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(k);
        for (int num : nums) {
            if (queue.size() < k) {
                queue.add(num);
            } else if (queue.peek()< num) {
                queue.remove();
                queue.add(num);
            }
        }
        return queue.peek();
    }
}
*/