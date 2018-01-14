/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null) return null;
        ListNode dummy1 = new ListNode(0);
        ListNode dummy2 = new ListNode(0);
        
        ListNode d1 = dummy1;
        ListNode d2 = dummy2;
        ListNode p = head;
        while(p != null) {
            if(p.val < x) {
                d1.next = p;
                d1 = d1.next;
            }else{
                d2.next = p;
                d2 = d2.next;
            }
            p = p.next;
        }
        d2.next = null;
        d1.next = dummy2.next;
        return dummy1.next;
    }
}
