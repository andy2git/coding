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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        int k = m;
        while(k > 1){
            d = d->next;
            k--;
        }
        
        ListNode *pre = nullptr;
        ListNode *cur = d->next;
        ListNode *next = nullptr;
        k = n-m+1;
        
        while(k > 0){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            k--;
        }
        d->next->next = cur;
        d->next = pre;
        
        return dummy.next;
    }
};
