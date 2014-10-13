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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        
        path_sum_helper(root, sum, vector<int>(), result);
        
        return result;
    }
private:
    void path_sum_helper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == sum){
                path.push_back(root->val);
                result.push_back(path);
            }
            return;
        }
        
        path.push_back(root->val);
        if(root->left) path_sum_helper(root->left, sum-root->val, path, result);
        if(root->right) path_sum_helper(root->right, sum-root->val, path, result);
    }
};
