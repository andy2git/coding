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
        if(root == nullptr) return true;
        
        int h = is_balanced(root);
        
        if(h < 0) return false;
        return true;
    }
private:
    int is_balanced(TreeNode *root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        int left = is_balanced(root->left);
        if(left < 0) return -1;
        
        int right = is_balanced(root->right);
        if(right < 0) return -1;
        
        if(abs(left-right) > 1) return -1;
        else return max(left, right)+1;
    }
    
};
