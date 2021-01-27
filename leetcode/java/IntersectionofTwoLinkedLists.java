/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode ha, ListNode hb) {
        if(ha == null || hb == null) return null;
        
        ListNode p = ha;
        ListNode q = hb;
        while(p != null && q != null) {
            // intersection during traversal
            if(p == q) return p;
            p = p.next;
            q = q.next;
        }
        if(p == null && q == null) return null;
        if(p == null) p = hb;
        else q = ha;
        
        while(p != null && q != null) {
            p = p.next;
            q = q.next;
        }
        
        if(p == null) p = hb;
        if(q == null) q = ha;
        
        while(p != null && q != null) {
            if (p == q) return p;
            p = p.next;
            q = q.next;
        }
        
        return null;
        
    }
}
