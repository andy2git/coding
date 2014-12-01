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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if(root == nullptr) return {}; 
        if(!root->left && !root->right) return {{root->val}};
     
        vector<vector<int>> result;
        queue<TreeNode *> p, q;
        p.push(root);
     
        vector<int> layer;
        while(!p.empty()){
            TreeNode *t = p.front();
            p.pop();
     
            layer.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
     
            if(p.empty()){
                swap(p, q); 
                result.push_back(layer);
                layer.clear();
            }   
        }   
     
        reverse(result.begin(), result.end());
        return result;
    }
};
