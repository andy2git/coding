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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
private:
    stack<TreeNode *> st;
    TreeNode *p = nullptr;
    
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        p = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
       while(p || !st.empty()){
           if(p){
               st.push(p);
               p = p->left;
           }else{
               return true;
           }
       }
       
       return false;
    }
    
    //@return: return next node
    TreeNode* next() {
        p = st.top();
        st.pop();
        
        TreeNode *t = p;
        p = p->right;
        return t;
    }
};
