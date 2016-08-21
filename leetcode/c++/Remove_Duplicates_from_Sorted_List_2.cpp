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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        while(cur){
            next = cur->next;
            
            int cnt = 0;
            while(next && next->val == cur->val){
                cnt++;
                next = next->next;
            }
            
            if(cnt > 0){
                cur = next;
            }else{
                d->next = cur;
                cur = next;
                d = d->next;
                d->next = nullptr;
            }
        }
        
        return dummy.next;
    }
};
