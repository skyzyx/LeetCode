// LeetCode #215: Kth Largest Element in an Array

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
public class Solution { // MinHeap, O(n) space, O(n) time.
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(); // In Java, this is a MinHeap.
        for (int num: nums)
            pq.offer(num);
            
        while (pq.size() > k)  
            pq.poll();
            
        return pq.peek();
    }
}
*/

public class Solution { // Minheap, O(k) space, O(n) time.
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> mypq = new PriorityQueue<Integer>(k); // In Java, this is a MinHeap.
        for (int num : nums) {
            if (mypq.size() < k) {
                mypq.offer(num);
            } else if (mypq.peek() < num) {
                mypq.poll();
                mypq.offer(num);
            }
        }
        return mypq.peek();
    }
}

/*
public class Solution {
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return -1;
            
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}
*/

