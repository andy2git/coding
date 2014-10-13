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
    ListNode *sortList(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            if(q->next) q = q->next->next;
            else break;
            p = p->next;
        }
        q = p->next;
        p->next = nullptr;
        
        ListNode *left = sortList(head);
        ListNode *right = sortList(q);
        return merge_list(left, right);
    }

private:
    ListNode *merge_list(ListNode *left, ListNode *right){
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        while(left && right){
            if(left->val < right->val){
                d->next = left;
                left = left->next;
                d = d->next;
            }else{
                d->next = right;
                right = right->next;
                d = d->next;
            }
        }
        
        if(left) d->next = left;
        if(right) d->next = right;
        
        return dummy.next;
    }
};
