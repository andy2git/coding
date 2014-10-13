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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        
        int cbit = 0;
        ListNode *p = l1;
        ListNode *pre = nullptr;
        ListNode *q = l2;
        int sum = 0;
        while(p && q){
            p->val = add(p->val, q->val, cbit);
            pre = p;
            p = p->next;
            q = q->next;
        }
        
        if(q) {
            pre->next = q;
            p = q;
        }
        
        while (p){
            p->val = add(p->val, 0, cbit);
            pre = p;
            p = p->next;
        }
        
        if(cbit == 1){
            pre->next = new ListNode(1);
        }
        
        return l1;
        
        // cbit = 1 after last node
    }
private:
    int add(int a, int b, int &cbit){
        int sum = 0;
        
        sum = a+b+cbit;
        cbit = 0;
        if(sum >= 10){
            sum %= 10;
            cbit = 1;
        }
        return sum;
    }
};
