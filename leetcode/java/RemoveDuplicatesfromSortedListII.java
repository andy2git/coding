/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) return null;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode pre = dummy;
        ListNode p = pre.next;
        while(p.next != null) {
            if(p.next.val == pre.next.val) p = p.next;
            else {
                if(pre.next == p) {
                    pre = p;
                    p = pre.next;
                } else {
                    pre.next = p.next;
                    p = pre.next;
                }
            }
        }
        
        if(pre.next != p) pre.next = p.next;
        return dummy.next;
    }
}
