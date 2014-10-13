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
    // partation into two list:
    // ------------------------
    // p1->   |<x|
    // p2->   |>=x|
    ListNode *partition(ListNode *head, int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode d1(0);
        ListNode d2(0);
        ListNode *p1 = &d1;
        ListNode *p2 = &d2;
        
        ListNode *cur = head;
        ListNode *next = nullptr;
        
        while(cur){
            next = cur->next;
            cur->next = nullptr;
            
            if(cur->val < x){
                p1->next = cur;
                p1 = p1->next;
            }else{
                p2->next = cur;
                p2 = p2->next;
            }
            cur = next;
        }
        p1->next = d2.next;
        
        return d1.next;
        
    }
};

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
    // regular insertion sort algorithm
    ListNode *partition(ListNode *head, int x) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *pre = nullptr;
        ListNode *p = head;
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        while(p && p->val < x){
            pre = p;
            p = p->next;
            d = d->next;
        }
        
        while(p){
            if(p->val < x){
                pre->next = p->next;
                p->next = d->next;
                d->next = p;
                p = pre->next;
                d = d->next;
            }else{
                pre = p;
                p = p->next;
            }
        }
        
        return dummy.next;
    }
};
