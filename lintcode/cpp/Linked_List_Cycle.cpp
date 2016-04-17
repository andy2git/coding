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
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            p = p->next;
            
            if(q->next) q = q->next->next;
            else return false;
            if(p == q) return true;
        }
        
        
        return false;
    }
};
