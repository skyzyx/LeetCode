// LeetCode #138: Copy List with Random Pointer

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null)
            return head;
            
        copyNext(head);
        correctRandom(head);
        return splitLists(head);
    }
    
    private void copyNext(RandomListNode head) {
        while (head != null) {
            RandomListNode newNode = new RandomListNode(head.label);
            newNode.random = head.random;
            
            newNode.next = head.next;
            head.next = newNode;
            head = head.next.next;
        }
    }
    
    private void correctRandom(RandomListNode head) {
        while (head != null) {
            if (head.next.random != null)
                head.next.random = head.random.next;
                
            head = head.next.next;
        }
    }
    
    private RandomListNode splitLists(RandomListNode head) {
        RandomListNode copiedListHead = head.next;
        while (head != null) {
            RandomListNode temp = head.next;
            head.next = temp.next;
            head = head.next;
            
            if (temp.next != null)
                temp.next = temp.next.next;
        }
        return copiedListHead;
    }
}