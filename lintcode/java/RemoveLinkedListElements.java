/**
 * Definition for singly-linked list.
 * public class ListNode { // make it private static class. 
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyNode = new ListNode(0);
        dummyNode.next = head;
        head = dummyNode;
        
        ListNode cur = head;
        while(cur.next != null){
            if(cur.next.val == val) {
                cur.next = cur.next.next;
            }else {
                cur = cur.next;
            }
        }
        return head.next;
    }


    public ListNode removeElements(ListNode head, int val) {
        // base case
        if(head == null) return null;
        // recursive 
        head.next = removeElements(head.next, val);
        // merge with subsolution
        return head.val == val ? head.next : head;
    }
}


