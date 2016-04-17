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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode dummy(0);
        ListNode *d = &dummy;
        
        int cb = 0;
        while(l1 && l2){
            l1->val = addition(l1->val, l2->val, cb);
            d->next = l1;
            
            d = d->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l2) d->next = l2;
        while(d->next){
            d->next->val = addition(d->next->val, 0, cb);
            d = d->next;
        }
        if(cb > 0) d->next = new ListNode(1);
        
        return dummy.next;
    }
private:
    int addition(int p, int q, int &cb){
        int x = p + q + cb;
        cb = 0;
        if(x >= 10){
            x %= 10;
            cb = 1;
        }
        
        return x;
    }
};
