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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(n <= 0 || !head) return head;
        
        /** Solution: the head of the list might change, 
          * so it is easier to add a dummy node at the beginning */
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        ListNode *p = d;
        ListNode *q = d;
        while(n > 0){
            q = q->next;
            n--;
        }
        
        while(q->next){
            p = p->next;
            q = q->next;
        }
        
        ListNode *t = p->next;
        p->next = p->next->next;
        delete t;
        return dummy.next;
    }
    
};
