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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == nullptr) return {};
        
        stack<TreeNode *> p, q;
        p.push(root);
        
        TreeNode *t = nullptr;
        while(!p.empty()){
            t = p.top();
            p.pop();
            
            if(t->left) p.push(t->left);
            if(t->right) p.push(t->right);
            q.push(t);
        }
       
        vector<int> result;
        while(!q.empty()){
            t = q.top();
            q.pop();
            result.push_back(t->val);
        }
        
        return result;
    }
};
    
