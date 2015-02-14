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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        if(!root) return {};
        
        stack<TreeNode *> st;
        st.push(root);
        
        vector<int> result;
        while(!st.empty()){
            TreeNode *t = st.top();
            st.pop();
            
            result.push_back(t->val);
            
            if(t->right) st.push(t->right);
            if(t->left) st.push(t->left);
        }
        
        return result;
    }
};



