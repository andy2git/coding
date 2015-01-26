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
    bool isBalanced(TreeNode *root) {
        
        return is_balanced_helper(root) >= 0;
    }
private:
    int is_balanced_helper(TreeNode *root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int l = is_balanced_helper(root->left);
        if(l == -1) return -1;
        
        int r = is_balanced_helper(root->right);
        if(r == -1) return -1;
        
        if(abs(l-r) > 1) return -1;
        else return max(l,r) + 1;
    }
};
