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
        if (lists == null) return null;
        // add all first option to the PQ
        PriorityQueue<ListNode> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1.val > o2.val) return 1;
            else if (o1.val == o2.val) return 0;
            else return -1;
        });
        
        for (ListNode list : lists) {
            if (list != null) pq.offer(list);
        }
        ListNode dummy = new ListNode(0);
        ListNode d = dummy;
        while (!pq.isEmpty()) {
            ListNode p = pq.poll();
            d.next = p;
            d = d.next;
            if (p.next != null) pq.offer(p.next);
        }
        return dummy.next;
    }
}
