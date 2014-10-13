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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                d->next = l1;
                d = d->next;
                l1 = l1->next;
            }else{
                d->next = l2;
                d = d->next;
                l2 = l2->next;
            }
        }
        
        if(l1) d->next = l1;
        if(l2) d->next = l2;
        
        return dummy.next;
    }
};
