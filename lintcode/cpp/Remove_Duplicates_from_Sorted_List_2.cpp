/**
 * Tips: similar to delete duplicated elements in sorted array
 * use cnt to denote if we need to include this node in the final output
 *
 */
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        
        ListNode *cur = head;
        ListNode *next = head->next;
        ListNode dummy(0);
        ListNode *d = &dummy;
        bool flag = false;
        
        while(cur){
            next = cur->next;
            
            flag = false;
            while(next && next->val == cur->val){
                next = next->next;
                flag = true;
            }
            
            if(flag){
               cur = next;
            }else{
                d->next = cur;
                d = d->next;
                cur = next;
            }
        }
        d->next = nullptr;
        
        return dummy.next;
    }
};
