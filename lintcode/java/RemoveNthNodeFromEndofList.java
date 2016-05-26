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
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode removeNthFromEnd(ListNode head, int n) {
        if(n <= 0 || head == null) return head;
        ListNode d = new ListNode(0);
        d.next = head;
        
        // advance q n steps
        ListNode p = d;
        ListNode q = d;
        q = advance(q, n);
        
        while(q.next != null){
            q = q.next;
            p = p.next;
        }
        
        p.next = p.next.next;
        return d.next;
    }
    
    ListNode advance(ListNode node, int n){
        while(n > 0){
            node = node.next;
            n--;
        }
        return node;
    }
}

