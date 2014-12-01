/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * This problem is similar to the LCA problem with parent link.
 *
 * Similar LCA problems:
 * - find the LCA of two given nodes in a BST, then we can perform pre-order traversal
 *   to find the FIRST node which is between [a, b]
 *
 *      * if x > a && x > b, then x = x->left
 *      * if x < a && x < b, then x = x->right
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lenA = list_length(headA);
        size_t lenB = list_length(headB);
        
        ListNode *p = headA;
        ListNode *q = headB;
        if(lenA < lenB){
            q = advance_steps(q, lenB-lenA);
        }else{
            p = advance_steps(p, lenA-lenB);
        }
        
        while(p && q){
            if(p == q) break;
            else{
                p = p->next;
                q = q->next;
            }
        }
        
        if(p) return p;
        else return nullptr;
    }
    
private:
    ListNode* advance_steps(ListNode *head, size_t steps){
        if(!head || steps <= 0) return head;
        
        while(head && steps > 0){
            head = head->next;
            steps--;
        }
        
        return head;
    }

    size_t list_length(ListNode *head){
        if(!head) return 0;
        
        ListNode *p = head;
        size_t len = 0;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
};
