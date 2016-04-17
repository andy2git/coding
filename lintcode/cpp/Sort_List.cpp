class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        
        //cut list into half
        ListNode *p = head;
        ListNode *q = head->next->next;
        while(q){
            if(q->next) q = q->next->next;
            else break;
            p = p->next;
        }
        
        q = p->next;
        p->next = nullptr;
        
        p = sortList(head);
        q = sortList(q);
        return mergeList(p, q);
    }
    
private:
    ListNode *mergeList(ListNode *p, ListNode *q){
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        while(p && q){
            if(p->val <= q->val){
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
