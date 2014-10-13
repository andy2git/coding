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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if(root == nullptr) return vector<vector<int>>();
        
        vector<vector<int>> result;
        queue<TreeNode *> p, q;
        p.push(root);
        
        vector<int> layer;
        TreeNode *t = nullptr;
        while(!p.empty()){
            t = p.front();
            
            layer.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            p.pop();
            if(p.empty()){
                swap(p, q);
                result.push_back(layer);
                layer.clear();
            }
        }
        
        return result;
    }
};
