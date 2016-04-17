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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        
        ListNode *p = head;
        ListNode *q = head->next;
        
        while(q){
            if(p->val == q->val){
                q = q->next;
                p->next = p->next->next;
            }else{
                p = p->next;
                q = q->next;
            }
        }
        
        return head;
    }
};
