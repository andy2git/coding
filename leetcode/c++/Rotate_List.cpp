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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        // for k is greater than n
        int n = listLength(head);
        k %= n;
        
        ListNode *p = head;
        ListNode *q = head;
        //advance m k steps 
        int m = k;
        while(m > 0){
            q = q->next;
            m--;
        }
        
        //move ptr p and q simuteniously
        while(q->next){
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = nullptr;
        
        return head;
    }
private:
    int listLength(ListNode *p){
        int len = 0;
        while(p){
            p = p->next;
            len++;
        }
        return len;
    }
};
