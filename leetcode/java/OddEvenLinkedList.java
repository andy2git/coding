/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) return null;
        ListNode da = new ListNode();
        ListNode db = new ListNode();
        
        ListNode odd = da;
        ListNode even = db;
        int i = 1;
        while(head != null) {
            if(i%2 == 1) {
                odd.next = head;
                odd = odd.next;
            } else {
                even.next = head;
                even = even.next;
            }
            i++;
            head = head.next;
        }
        even.next = null;
        odd.next = db.next;
        return da.next;
    }
}
