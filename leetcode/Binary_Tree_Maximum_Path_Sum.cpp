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
    int maxPathSum(TreeNode *root) {
        int max_sum = INT_MIN;
        
        max_path_sum_helper(root, max_sum);
        
        return max_sum;
    }
    
private:
    int max_path_sum_helper(TreeNode *root, int &max_sum){
        if(root == nullptr) return 0;
        // NOT NEEDED - STILL NEED TO CHECK IF IT IS THE MAX_SUM
        // if(root->left == nullptr && root->right == nullptr) return root->val;
        
        //if(root->left == nullptr && root->right == nullptr){
        //    if(root->val > max_sum) max_sum = root->val;
        //    return root->val;  
        //} 
        
        int left = max_path_sum_helper(root->left, max_sum);
        int right = max_path_sum_helper(root->right, max_sum);
        
        // one option for max path sum
        int sum = root->val;
        if(left > 0) sum +=left;
        if(right > 0) sum += right;
        if(sum > max_sum){
            max_sum = sum;
        }
        
        //max path with the root node included for the upper level
        return max(root->val, max(root->val+left, root->val+right));
    }
};

/* OBSERVATION:
 * Any max path has to go through a 'root' node, so recursivly go 
 * all the way into the bottom, and the max value will be one of 
 * the potential path with the internal node.
 */
