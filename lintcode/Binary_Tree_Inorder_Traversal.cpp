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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        if(!root) return {};
        
        stack<TreeNode *> st;
        TreeNode *p = root;
        vector<int> result;
        
        while(!st.empty() || p){
            if(p){
                st.push(p);
                p = p->left;
            }else{
                TreeNode *t = st.top();
                st.pop();
                result.push_back(t->val);
                p = t->right;
            }
        }
        
        return result;
    }
};


