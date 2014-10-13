/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == nullptr) return nullptr;
        
        ListNode *p = head;
        ListNode *q = head;
        
        while(q && n > 0){
            q = q->next;
            n--;
        }
        if(q == nullptr){return p->next;}
        
        while(q->next){
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
