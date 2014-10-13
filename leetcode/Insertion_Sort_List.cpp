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
    ListNode *insertionSortList(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *pre = head;
        ListNode *p = head->next;
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        while(p){
            if(pre->val <= p->val){
                pre = p;
                p = p->next;
            }else{
                d = &dummy;
                while(d->next->val < p->val){
                    d = d->next;
                }
                
                pre->next = p->next;
                p->next = d->next;
                d->next = p;
                p = pre->next;
            }
        }
        
        return dummy.next;
    }
};
