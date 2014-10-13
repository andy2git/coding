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
    vector<int> preorderTraversal(TreeNode *root) {
        if(!root) return {};
        
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        
        TreeNode *p = nullptr;
        while(!st.empty()){
            p = st.top();
            st.pop();
            result.push_back(p->val);

            if(p->right) st.push(p->right);
            if(p->left) st.push(p->left);
        }
        
        return result;
    }
};
