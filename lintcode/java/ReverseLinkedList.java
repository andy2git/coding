/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        if(head == null || head.next == null) return head;
        
        ListNode pre = null;
        ListNode cur = head;
        
        ListNode next = null;
        while(cur != null) {
             next = cur.next;
             cur.next = pre;
             pre = cur;
             cur = next;
        }
        
        return pre;
    }
}

