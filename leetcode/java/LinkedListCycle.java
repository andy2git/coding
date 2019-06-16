/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false;
        
        ListNode p = head;
        ListNode q = head.next.next;
        
        while(q != null) {
            if(p == q) return true;
            p = p.next;
            if(q.next == null) return false;
            q = q.next.next;
        }
        return false;
    }
}
