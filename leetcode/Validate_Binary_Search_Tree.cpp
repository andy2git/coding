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
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        return isBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    // use long for overflow problem
    // NOTE: 
    // -----
    // In BST, key cannot be duplicated
    bool isBSTHelper(TreeNode *root, long l, long h){
        if(!root) return true;
        if(root->val <= l || root->val >= h) return false;
        
        return isBSTHelper(root->left, l, root->val)
            && isBSTHelper(root->right, root->val, h);
    }
};
