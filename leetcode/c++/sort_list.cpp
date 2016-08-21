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
       if(!head) return nullptr;
       if(!head->next) return head;
       
       ListNode *p = head;
       ListNode *q = head->next->next;
       
       while(q){
           if(q->next) q = q->next->next;
           else break;
           p = p->next;
       }
       q = p->next;
       p->next = nullptr;
       p = head;
       
       p = sortList(p);
       q = sortList(q);
       
       return mergeList(p, q);
       
    }
private:
    ListNode *mergeList(ListNode *p, ListNode *q){
        if(!p) return q;
        if(!q) return p;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        while(p && q){
            if(p->val < q->val){
                d->next = p;
                p = p->next;
            }else{
                d->next = q;
                q = q->next;
            }
            d = d->next;
        }
        
        if(p) d->next = p;
        if(q) d->next = q;
        
        return dummy.next;
    }
};
