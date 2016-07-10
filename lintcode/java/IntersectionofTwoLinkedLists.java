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
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode 
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == headB) return headA;
        if(headA == null || headB == null) return null;
        
        ListNode p = headA;
        ListNode q = headB;
        
        while(p != null && q != null){
            p = p.next;
            q = q.next;
        }
        
        if(q != null) p = headB;
        else if(p != null) q = headA;
        
        while(p != null && q != null) {
            p = p.next;
            q = q.next;
        }
        
        if(q != null) p = headB;
        else if(p != null) q = headA;
        
        while(p != null && q != null){
            if(p == q) return p;
            p = p.next;
            q = q.next;
        }
        
        return null;
    }  


    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == headB) return headA;
        if(headA == null || headB == null) return null;
        
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        
        int lenDiff = Math.abs(lenA - lenB);
        
        ListNode p, q;
        if(lenA < lenB) {
            p = headA;
            q = advanceNstep(headB, lenDiff);
        }else {
            p = headB;
            q = advanceNstep(headA, lenDiff);
        }
        
        while(p != null && q != null){
            if(p == q) return p;
            p = p.next;
            q = q.next;
        }
        
        return null;
    }
    
    private ListNode advanceNstep(ListNode head, int n){
        while(head != null && n > 0){
            head = head.next;
            n--;
        }
        return head;
    }
    
    private int getListLength(ListNode head){
        int count = 0;
        
        while(head != null) {
            count++;
            head = head.next;
        }
        return count;
    }
}
