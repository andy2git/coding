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
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) return 0;
        
        return sum_helper(root, 0);
    }
    
private:
    int sum_helper(TreeNode *root, int p){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return p*10+root->val;
        
        int t = p*10+root->val;
        int sum = 0;
        if(root->left) sum += sum_helper(root->left, t);
        if(root->right) sum += sum_helper(root->right, t);
        
        return sum;
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
    int sumNumbers(TreeNode *root) {
        if(root == nullptr) return 0;
        
        int sum = 0;
        sum_helper(root, 0, sum);
        return sum;
    }
    
private:
    void sum_helper(TreeNode *root, int p, int &sum){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            sum += p*10+root->val;
            return;
        }
        
        int t = p*10+root->val;
        if(root->left) sum_helper(root->left, t, sum);
        if(root->right) sum_helper(root->right, t, sum);
    }
};
