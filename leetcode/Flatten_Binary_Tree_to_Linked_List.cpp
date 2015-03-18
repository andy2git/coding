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
    void flatten(TreeNode *root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *pre = nullptr;
        
        while(!st.empty()){
            TreeNode *cur = st.top();
            st.pop();
            
            if(pre) {
                pre->left = nullptr;
                pre->right = cur;
            }
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
            
            pre = cur;
        }
        
        // last node must be a leaf node, so it is okay to leave it out
    }
};
