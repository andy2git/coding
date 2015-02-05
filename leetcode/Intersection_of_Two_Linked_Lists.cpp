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
 * - find the LCA of two given nodes in a BST is easier, then we can perform pre-order traversal
 *   to find the FIRST node which is between [a, b]
 *
 *      * if x > a && x > b, then x = x->left
 *      * if x < a && x < b, then x = x->right
 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        
        ListNode *p = headA;
        ListNode *q = headB;
        
        // find the length diff between two lists
        movePtrsToEnd(p, q, headA, headB);
        
        //fill the gap 
        movePtrsToEnd(p, q, headA, headB);
        
        //find the first intersection
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
private:
    void movePtrsToEnd(ListNode *&p, ListNode *&q, ListNode *headA, ListNode *headB){
        while(p && q){
            p = p->next;
            q = q->next;
        }
        if(!p) p = headB;
        if(!q) q = headA;
    }
};
