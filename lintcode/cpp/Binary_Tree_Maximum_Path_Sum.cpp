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
    int maxPathSum(TreeNode *root) {
        // write your code here
        int mp = INT_MIN;
        
        maxPathSumHelper(root, mp);
        
        return mp;
    }
private:
    int maxPathSumHelper(TreeNode *root, int &mp){
        if(!root) return 0;
        
        if(!root->left && !root->right) {
            if(root->val > mp) mp = root->val;
            return root->val;
        }
        
        int l = maxPathSumHelper(root->left, mp);
        int r = maxPathSumHelper(root->right, mp);
        
        int p = root->val;
        if(l > 0) p += l;
        if(r > 0) p += r;
        if(p > mp) mp = p;
        
        return max(max(root->val, root->val+r), root->val+l);
        
        
    }
};
