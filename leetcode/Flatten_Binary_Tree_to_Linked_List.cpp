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
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *p = nullptr;
        TreeNode *pre = nullptr;
        
        while(!st.empty()){
            p = st.top();
            st.pop();
            
            if(pre){
                pre->left = nullptr;
                pre->right = p;
            }
            pre = p;
            
            if(p->right) st.push(p->right);
            if(p->left) st.push(p->left);
        }
        
        pre->left = pre->right = nullptr;
    }
};
