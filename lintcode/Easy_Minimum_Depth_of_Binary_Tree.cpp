/**
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(l == 0) return r+1;
        if(r == 0) return l+1;
        
        return min(l,r)+1;
    }
};
