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
        
        return result;
    }
};

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        if(!root) return {};
        if(!root->left && !root->right) return {{root->val}};
        
        queue<TreeNode *> que;
        que.push(root);
        que.push(nullptr);
        
        vector<vector<int>> result;
        vector<int> layer;

        while(!que.empty()){
            TreeNode *t = que.front();
            que.pop();
            if(t == nullptr){
                // no more elems to traverse                 
                if(layer.empty()) break;

                result.push_back(layer);
                que.push(nullptr);
                layer.clear();
            }else{
                layer.push_back(t->val);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
        }
        
        return result;
    }
};
