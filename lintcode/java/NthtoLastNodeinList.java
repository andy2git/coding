/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode nthToLast(ListNode head, int n) {
        if(head == null) return head;
        if(n <= 0) throw new IllegalArgumentException("xxx");
        
        ListNode p = head;
        ListNode q = head;
        
        while(n > 0) {
            q = q.next;
            n--;
        }
        
        while(q != null){
            p = p.next;
            q = q.next;
        }
        
        return p;
    }
}
// NOTE: watch out for cases where only one node presents

