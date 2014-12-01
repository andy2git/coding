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
        
        // copy ctor 
        //path_sum_helper(root, sum, vector<int>(), result);
        path_sum_helper(root, sum, {}, result);
        
        return result;
    }
private:
    void path_sum_helper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result){
        if(!root) return;
        //leaf node - check if it is a valid path
        if(!root->left && !root->right){
            if(root->val == sum){
                path.push_back(root->val);
                result.push_back(path);
            }
            return;
        }
        
        // more path to explore
        path.push_back(root->val);
        if(root->left) path_sum_helper(root->left, sum-root->val, path, result);
        if(root->right) path_sum_helper(root->right, sum-root->val, path, result);
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root == nullptr) return {};
        if(!root->left && !root->right){
            if(root->val == sum) return {{root->val}};
            else return {};
        }
        
        // return the final result from bottom
        vector<vector<int>> left = pathSum(root->left, sum-root->val);
        vector<vector<int>> right = pathSum(root->right, sum-root->val);
        
        vector<vector<int>> result;
        for(int i = 0; i < left.size(); i++){
            if(!left[i].empty()){
                left[i].insert(left[i].begin(), root->val);
                result.push_back(left[i]);
            }
        }
        
        for(int i = 0; i < right.size(); i++){
            if(!right[i].empty()){
                right[i].insert(right[i].begin(), root->val);
                result.push_back(right[i]);
            }
        }
        
        return result;
    }
};
