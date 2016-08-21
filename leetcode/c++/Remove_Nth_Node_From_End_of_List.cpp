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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head || n <= 0) return head;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        // advance q n steps ahead
        ListNode *p = d;
        ListNode *q = d;
        int k = n;
        while(k > 0){
            q = q->next;
            k--;
        }
        
        // need a ptr one element ahead, so check q->next
        while(q->next){
            p = p->next;
            q = q->next;
        }
        
        ListNode *t = p->next->next;
        // do not forget to delete
        delete p->next;
        p->next = t;
        
        return dummy.next;
    }
};
