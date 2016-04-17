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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        if(!root) return {};
        
        stack<TreeNode *> st;
        st.push(root);
        
        vector<int> result;
        while(!st.empty()){
            TreeNode *t = st.top();
            st.pop();
            result.push_back(t->val);
            
            if(t->left) st.push(t->left);
            if(t->right) st.push(t->right);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};


