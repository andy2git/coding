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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(!head || !head->next) return nullptr;
        
        //check if the list has cycle
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            p = p->next;
            if(q->next) q = q->next->next;
            else return nullptr;
            
            if(p == q) break;
        }
        if(!q) return nullptr;
        
        // find the length of the cycle
        int len = cycleLen(p);
        
        // find the intersection point
        p = q = head;
        q = advance(q, len);
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
private:
    int cycleLen(ListNode *p){
        ListNode *q = p->next;
        int cnt = 1;
        
        while(q != p){
            q = q->next;
            cnt++;
        }
        return cnt;
    }

    ListNode *advance(ListNode *p, int len){
        if(len <= 0) return p;
        while(len > 0){
            p = p->next;
            len--;
        }
        
        return p;
    }
};
