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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    public ListNode mergeKLists(List<ListNode> lists) {  
        if(lists == null) throw new IllegalArgumentException("xxx");
        if(lists.isEmpty()) return null;
        
        // can be replaced with lambda functions
        Queue<ListNode> pQueue = new PriorityQueue<ListNode>(lists.size(), new Comparator<ListNode>() {
            @Override
            public int compare(ListNode lhs, ListNode rhs) {
                if(lhs.val > rhs.val) return 1;
                else if(lhs.val < rhs.val) return -1;
                else return 0;
            }
        });
        
        for(ListNode list: lists){
            if(list != null) pQueue.offer(list);
        }
        
        ListNode dummy = new ListNode(0);
        ListNode d = dummy;
        while(!pQueue.isEmpty()){
            ListNode t = pQueue.poll();
            d.next = t;
            d = d.next;
            if(t.next != null) pQueue.offer(t.next);
        }
        
        return dummy.next;
    }
}
