/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** Solution:
 *  t = x + w + ny
 * 2t = x + w + my
 *  x = (m-2n)y - w : this means that if we use one ptr to go x steps, 
 *   then the other one will go (m-2n) loops but w steps short
 *
 * Solution#2 by Xi
 * find the size of loop y. Then use two ptrs starting from beginning, 
 * but y steps apart. the next time they meet again. 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return nullptr;
        
        // p and q has to start from the same point
        // That is how the math is done based on the same start point.
        ListNode *p = head;
        ListNode *q = head;
        
        while(q){
            p = p->next;
            if(q->next) {
                q = q->next->next;
            }else break;
            
            if(p == q) break;
        }
        
        if(p != q) return nullptr;
        
        q = head;
        while(q != p){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
