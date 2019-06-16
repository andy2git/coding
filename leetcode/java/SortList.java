/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        
        // halve the list
        ListNode p = head;
        ListNode q = head.next.next;
        
        while(q != null) {
            p = p.next;
            if(q.next == null) break;
            q = q.next.next;
        }
        
        q = p.next;
        p.next = null;
        p = head;
        
        ListNode first = sortList(p);
        ListNode second = sortList(q);
        
        return merge(first, second);
    }
    
    private ListNode merge(ListNode f, ListNode s) {
        ListNode dummy = new ListNode(0);
        
        ListNode p = dummy;
        while(f != null && s != null) {
            if(f.val < s.val) {
                p.next = f;
                f = f.next;
            } else {
                p.next = s;
                s = s.next;
            }
            p = p.next;
        }
        
        if(f != null) p.next = f;
        if(s != null) p.next = s;
        return dummy.next;
    }
}
