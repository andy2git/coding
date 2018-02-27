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
        ListNode cur = head;
        ListNode next = cur.next;
        while(next != null) {
            if(cur.val == next.val) {
                cur.next = next.next;
            }else {
                cur = next;
            }
            next = cur.next;
        }
        return head;
    }
}
