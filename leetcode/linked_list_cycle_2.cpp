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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        
        // p and q has to start from the same point
        ListNode *p = head;
        ListNode *q = head;
        
        while(q){
            p = p->next;
            if(q->next) {
                q = q->next->next;
            }else break;
            
            if(p == q) break;
        }
        
        if(p != q) return nullptr;
        
        q = head;
        while(q != p){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
