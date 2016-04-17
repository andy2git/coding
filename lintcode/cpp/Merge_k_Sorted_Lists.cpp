/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

/** Time complexity: 
 *  1. construct the priority_queue of size k. lg1 + lg2 + lg3 + lgk = lg(k!)
 *  2. merge the rest of the node, and each one has complexity O(N*lgk), where N is the rest of the nodes.
 */
struct listNode_cmp{
    bool operator()(ListNode *lhs, ListNode *rhs){
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode *, vector<ListNode *>, listNode_cmp> minHeap;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) minHeap.push(lists[i]);
        }
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        while(!minHeap.empty()){
            ListNode *t = minHeap.top();
            d->next = t;
            d = d->next;
            minHeap.pop();
            if(t->next) minHeap.push(t->next);
        }
        
        return dummy.next;
    }
};
