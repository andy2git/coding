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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(!head) return nullptr;
        
        ListNode dummy1(0);
        ListNode *d1 = &dummy1;
        ListNode dummy2(0);
        ListNode *d2 = &dummy2;
        
        while(head){
            if(head->val < x) {
                d1->next = head;
                d1 = d1->next;
            }else{
                d2->next = head;
                d2 = d2->next;
            }
            head = head->next;
        }
        
        d1->next = dummy2.next;
        d2->next = nullptr;
        
        return dummy1.next;
    }
};
