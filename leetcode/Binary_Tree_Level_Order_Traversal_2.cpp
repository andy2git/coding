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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if(root == nullptr) return vector<vector<int>>();
        
        queue<TreeNode *> p, q;
        p.push(root);
        
        vector<vector<int>> result;
        vector<int> layer;
        TreeNode *t = nullptr;
        
        while(!p.empty()){
            t = p.front();
            p.pop();
            layer.push_back(t->val);
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            if(p.empty()){
                swap(p, q);
                result.insert(result.begin(), layer);
                layer.clear();
            }
        }
        
        return result;
    }
};
