/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        ListNode pre = null;
        ListNode cur = head;
        ListNode next = cur.next;
        while(cur != null) {
            cur.next = pre;
            pre = cur;
            cur = next;
            if(cur == null) break;
            else next = cur.next;
        }
        return pre;
    }
}
