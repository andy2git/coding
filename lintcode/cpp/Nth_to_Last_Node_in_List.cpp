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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if(!head || n == 0) return nullptr;
        ListNode *p = head;
        ListNode *q = head;
        while(n > 0){
            q = q->next;
            n--;
        }
        while(q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
