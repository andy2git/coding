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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return is_symmetric_helper(root->left, root->right);
    }
    
    bool is_symmetric_helper(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        
        return (p->val == q->val) && is_symmetric_helper(p->right, q->left)
            && is_symmetric_helper(p->left, q->right);
    }
};
