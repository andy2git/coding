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
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        
        return is_bst_helper(root, INT_MIN, INT_MAX);
    }
private:
    bool is_bst_helper(TreeNode *root, int min, int max){
        // speical case
        if(root == nullptr) return true;
        
        if(root->val <= min || root->val >= max) return false;
        
        return is_bst_helper(root->left, min, root->val) && is_bst_helper(root->right, root->val, max);
        
    }

};
