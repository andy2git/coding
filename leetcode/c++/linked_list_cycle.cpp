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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head->next == nullptr) return false;
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q && p != q){
            p = p->next;
            if(q->next) q = q->next->next;
            else break;
        }
        
        if(p == q) return true;
        else return false;
    }
};

