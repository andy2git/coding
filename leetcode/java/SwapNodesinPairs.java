/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null;
        ListNode d = new ListNode(0);
        d.next = head;
        ListNode r = d;
        while(r.next != null && r.next.next != null) {
            ListNode p = r.next;
            ListNode q = r.next.next;
            r.next = q;
            p.next = q.next;
            q.next = p;
            r = p;
        }
        return d.next;
    }
}

// recursive solution

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode t = head.next;
        head.next = swapPairs(head.next.next);
        t.next = head;
        return t;
    }
}
