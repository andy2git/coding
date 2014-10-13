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
    vector<int> inorderTraversal(TreeNode *root) {
        if(!root) return {};
        
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *p = root;
        
        while(p || !st.empty()){
            if(p){
                st.push(p);
                p = p->left;
            }else{
                p = st.top();
                st.pop();
        
                result.push_back(p->val);        
                p = p->right;
            }
        }
        
        return result;
    }
};
