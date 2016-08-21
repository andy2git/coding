/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Solution: leaf node returns the path sum to the parent node. 
 *
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) return 0;
        
        return sum_helper(root, 0);
    }
    
private:
    int sum_helper(TreeNode *root, int p){
        if(root->left == nullptr && root->right == nullptr) return p*10+root->val;
        
        int t = p*10+root->val;
        int sum = 0;
        if(root->left) sum += sum_helper(root->left, t);
        if(root->right) sum += sum_helper(root->right, t);
        
        return sum;
    }
};

/**
 * sum all the value at the leaf node
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) return 0;
        
        int sum = 0;
        sum_helper(root, 0, sum);
        return sum;
    }
    
private:
    void sum_helper(TreeNode *root, int p, int &sum){
        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            sum += p*10+root->val;
            return;
        }
        
        int t = p*10+root->val;
        if(root->left) sum_helper(root->left, t, sum);
        if(root->right) sum_helper(root->right, t, sum);
    }
};
