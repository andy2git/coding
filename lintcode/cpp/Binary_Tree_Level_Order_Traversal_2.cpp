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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderButtom(TreeNode *root) {
        // write your code here
        if(!root) return {};
        
        queue<TreeNode *> p, q;
        p.push(root);
        vector<vector<int>> result;
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
