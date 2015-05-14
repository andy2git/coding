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
    vector<int> rightSideView(TreeNode *root) {
        if(!root) return {};
        
        queue<TreeNode *> p, q;
        p.push(root);
        
        vector<int> result;
        while(!p.empty()){
            if(p.size() == 1) result.push_back((p.front())->val);
            TreeNode *t = p.front();
            p.pop();
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            if(p.empty()) swap(p, q);
        }
        
        return result;
    }
};
