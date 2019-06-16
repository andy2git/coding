/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0) return null;
        if(lists.length == 1) return lists[0];
        
        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(l -> l.val));
        
        for(ListNode l : lists) {
            if (l != null) pq.offer(l);
        }
        
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        while (!pq.isEmpty()) {
            ListNode t = pq.poll();
            p.next = t;
            p = p.next;
            if(t.next != null) pq.offer(t.next);
        }
        
        return dummy.next;
    }
}
