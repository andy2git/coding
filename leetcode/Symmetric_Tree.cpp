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
        if(root == nullptr) return true;
        
        return is_symmetric_helper(root->left, root->right);
    }
    
    bool is_symmetric_helper(TreeNode *left, TreeNode *right){
        if(left == nullptr && right == nullptr) return true;
        else if(left == nullptr && right) return false;
        else if(left && right == nullptr) return false;
        
        
        if(left->val != right->val) return false;
        return is_symmetric_helper(left->right, right->left) && is_symmetric_helper(left->left, right->right);
        
    }
};
