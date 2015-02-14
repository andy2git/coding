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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        if(!root) return {};
        
        queue<TreeNode *> p, q;
        vector<vector<int>> result;
        vector<int> layer;
        p.push(root);
        
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
