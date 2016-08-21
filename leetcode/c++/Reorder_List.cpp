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
    void reorderList(ListNode *head) {
        if(head == nullptr) return;
        if(head->next == nullptr) return;
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            if(q->next) q = q->next->next;
            else break;
            p = p->next;
        }
        ListNode *half = p->next;
        p->next = nullptr;
        
        half = reverse_list(half);
        head = merge_list(head, half);
    }
private:
    ListNode* reverse_list(ListNode *head){
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
    
    ListNode* merge_list(ListNode *l1, ListNode *l2){
        
        ListNode dummy(0);
        ListNode *p = &dummy;
        bool flag = true;
        
        while(l1 && l2){
            if(flag) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
                flag = false;
            }else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                flag = true;
            }
        }
        
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        
        return dummy.next;
    }
};
