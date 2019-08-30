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
        ListNode pre = null;
        ListNode cur = head;
        ListNode next = null;
        
        while(cur != null) {
            next = cur.next;
            cur.next = pre;
            cur = next;
            pre = cur;
        }
        return pre;
    }
}

// Recursive version - walk through the recursive stack
// recursive solution is actually reverse the pointer in a right -> left fashion.
// Iterative appache is going from left -> right
public ListNode reverseList(ListNode head) {
    // there are two stop conditions in this case 
    if (head == null || head.next == null) return head;

    ListNode p = reverseList(head.next);
    // this is it!! head has not been modified at all, so we head.next still points
    // to the end of reversed list
    head.next.next = head;
    head.next = null;
    return p;
}
