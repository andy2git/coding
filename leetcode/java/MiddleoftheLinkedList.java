/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        if (head == null || head.next == null) return head;
        
        ListNode p = head;
        ListNode q = head.next.next;
        
        while (q != null) {
            if(q.next == null) break;
            q = q.next.next;
            p = p.next;
        }
        
        return p.next;
    }
}
