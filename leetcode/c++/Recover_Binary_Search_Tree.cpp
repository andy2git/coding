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
    void recoverTree(TreeNode *root) {
        
        TreeNode *pre = nullptr;
        TreeNode *a = nullptr;
        TreeNode *b = nullptr;
        
        recover_tree_helper(root, pre, a, b);
        
        swap(a->val, b->val);
        
        return;
    }
private:
    void recover_tree_helper(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b){
        if(root == nullptr) return;
        recover_tree_helper(root->left, pre, a, b);
        
        if(pre){
            if(pre->val > root->val){
                if(a == nullptr){
                    a = pre;
                    b = root;
                }else{
                    b = root;
                }
            }
        }
        pre = root;
        recover_tree_helper(root->right, pre, a, b);
    }
};
