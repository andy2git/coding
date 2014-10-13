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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if(root == nullptr) return vector<vector<int>>();
        
        vector<vector<int>> result;
        queue<TreeNode *> p, q;
        p.push(root);
        
        vector<int> layer;
        bool flag = true;
        TreeNode *t = nullptr;
        while(!p.empty()){
            t = p.front();
            
            layer.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            p.pop();
            if(p.empty()){
                swap(p, q);
                if(flag){
                    result.push_back(layer);
                    flag = false;
                }else{
                    reverse(layer.begin(), layer.end());
                    result.push_back(layer);
                    flag = true;
                }
                layer.clear();
            }
        }
        
        return result;
    }
};
