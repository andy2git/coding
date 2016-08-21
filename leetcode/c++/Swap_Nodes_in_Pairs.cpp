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
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        while(cur && cur->next){
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            d->next = next;
            d = cur;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};


/**
 * Solution 2: split the list into two, and merge them back into one.
 * 
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode dummy1(0);
        ListNode *d1 = &dummy1;
        ListNode dummy2(0);
        ListNode *d2 = &dummy2;
        
        bool flag = true;
        ListNode *p = head;
        ListNode *t = nullptr;
        while(p){
            t = p->next;
            p->next = nullptr;
            if(flag){
                d1->next = p;
                d1 = d1->next;
                flag = false;
            }else{
                d2->next = p;
                d2 = d2->next;
                flag = true;
            }
            p = t;
        }
        
        return merge_list(dummy1.next, dummy2.next);
    }
private:
    ListNode *merge_list(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        bool flag = true;
        while(l1 && l2){
            if(flag){
                d->next = l2;
                l2 = l2->next;
                d = d->next;
                flag = false;
            }else{
                d->next = l1;
                l1 = l1->next;
                d = d->next;
                flag = true;
            }
        }
        
        if(l1) d->next = l1;
        if(l2) d->next = l2;
        
        return dummy.next;
    }
};
