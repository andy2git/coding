/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        
        ListNode *p = head;
        ListNode *q = head->next->next;
        
        while(q){
            if(q->next) q= q->next->next;
            else break;
            
            p = p->next;
        }
        
        q = p->next;
        p->next = nullptr;
        
        TreeNode *root = new TreeNode(q->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(q->next);
        
        return root;
    }
};
