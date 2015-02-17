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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            if(q->next) q = q->next->next;
            else break;
            p = p->next;
        }
        ListNode *t = p->next;
        p->next = nullptr;
        
        TreeNode *root = new TreeNode(t->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(t->next);
        
        return root;
    }
};
