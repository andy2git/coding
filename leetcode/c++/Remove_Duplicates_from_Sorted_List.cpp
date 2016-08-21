/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Solution:
 * ---------
 * check if the next element is a duplicate of the current one
 * 1. if yes, remove the next element
 * 2. if no, the next element becomes the current elem 
 *  
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        
        ListNode *p = head;
        ListNode *q = nullptr;
        while(p->next){
            q = p->next;
            
            if(p->val == q->val){
                p->next = q->next;
            }else{
                p = p->next;
            }
        }
        
        return head;
    }
};
