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
        //if(root == nullptr) return vector<vector<int>>();
        if(root == nullptr) return {};
        
        vector<vector<int>> result;
        queue<TreeNode *> p, q;
        p.push(root);
        
        vector<int> layer;
        bool flag = false;

        while(!p.empty()){
            TreeNode *t = p.front();
            p.pop();
            
            layer.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            if(p.empty()){
                swap(p, q);
                if(flag) reverse(layer.begin(), layer.end());

                result.push_back(layer);
                layer.clear();
                flag = !flag;
            }
        }
        
        return result;
    }
};
