/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(!head || !head->next) return;
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        while(q){
            if(q->next) q = q->next->next;
            else break;
            p = p->next;
        }
        q = p->next;
        p->next = nullptr;
        
        q = reverse(q);
        
        // merge head and q
        mergeList(head, q);
    }
private:
    void mergeList(ListNode *p, ListNode *q){
        if(!p || ! q) return;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        bool flag = true;
        while(p && q){
            if(flag){
                d->next = p;
                p = p->next;
            }else{
                d->next = q;
                q = q->next;
            }
            d = d->next;
            flag = !flag;
        }
        
        if(p) d->next = p;
        if(q) d->next = q;
    }

    ListNode *reverse(ListNode *head) {
        // write your code here
        if(!head || !head->next) return head;
        
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
};
