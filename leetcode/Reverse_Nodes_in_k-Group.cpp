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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode *h = head;
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        int m = k;
        while(cur){
            if(!can_forward(cur, k)) break;
            
            while(m > 0){
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                m--;
            }
            
            if(m == 0){
                d->next = pre;
                h->next = cur;
                d = h;
                h = cur;
                m = k;
                pre = nullptr;
            }
        }
      
        return dummy.next;
        
    }
private:
    bool can_forward(ListNode *head, int k){
        while(head){
            head = head->next;
            k--;
            if(k == 0) return true;
        }
        return false;
    }
};
