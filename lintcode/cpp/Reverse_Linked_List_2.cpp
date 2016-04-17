/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(m == n || !head) return head;
        
        /** Solution: the head of the list might change, 
          * so it is easier to add a dummy node at the beginning */
        ListNode dummy(0);
        ListNode *d = &dummy;
        d->next = head;
        
        int k = m;
        while(k > 1){
            d = d->next;
            k--;
        }
        
        ListNode *pre = d->next;
        ListNode *cur = pre->next;
        k = n-m;
        while(k > 0){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            k--;
        }
        d->next->next = cur;
        d->next = pre;
        
        return dummy.next;
    }
};
