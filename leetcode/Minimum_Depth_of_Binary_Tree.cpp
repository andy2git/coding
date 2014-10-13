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
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        
        if(root->left && root->right) return min(minDepth(root->left), minDepth(root->right))+1;
        else if(root->left == nullptr && root->right) return minDepth(root->right)+1;
        else if(root->left && root->right == nullptr) return minDepth(root->left)+1;
        else return 1;
    }
};

/**
 * Watch out for internal node with only one child
 * There are four cases for a node:
 * 1. left and right
 * 2. left
 * 3. right
 * 4. leaf node
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
class Solution_2 {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int mL = minDepth(root->left);
        int mR = minDepth(root->right);
        
        if(mL <= 0) return mR+1;
        if(mR <= 0) return mL+1;
        
        return min(mL, mR)+1;
    }
};
