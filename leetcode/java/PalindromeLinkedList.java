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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        
        ListNode p = head;
        ListNode q = p.next;
        boolean odd = false;
        while(q.next != null) {
            p = p.next;
            q = q.next.next;
            if (q == null) {
                odd = true;
                break;
            }
        }
        q = p.next;
        
        // push values into stack
        Deque<Integer> st = new ArrayDeque<>();
        p = head;
        while(p != q) {
            st.push(p.val);
            p = p.next;
        }
        if(odd) st.pop();
        
        // palindrome check
        while(q!= null){
            if(q.val != st.pop()) return false;
            q = q.next;
        }
        return true;
    }
}
