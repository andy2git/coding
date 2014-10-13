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
    vector<TreeNode *> generateTrees(int n) {
        return tree_helper(1, n);
    }
    
    vector<TreeNode *> tree_helper(int s, int e){
        vector<TreeNode *> result;
        if(s > e) {
            result.push_back(nullptr);
            return result;
        }
        
        if(s == e) {
            result.push_back(new TreeNode(s));
            return result;
        }
        
        for(int i = s; i <= e; i++){
            vector<TreeNode *> left = tree_helper(s, i-1);
            vector<TreeNode *> right = tree_helper(i+1, e);
            
            for(int p = 0; p < left.size(); p++){
                for(int q = 0; q < right.size(); q++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[p];
                    root->right = right[q];
                    
                    result.push_back(root);
                }
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        
        tree_helper(result, 1, n);
        return result;
    }
    
    void tree_helper(vector<TreeNode *> &result, int s, int e){
        if(s > e) {
            result.push_back(nullptr);
            return;
        }
        
        if(s == e) {
            result.push_back(new TreeNode(s));
            return;
        }
        
        for(int i = s; i <= e; i++){
            vector<TreeNode *> left;
            tree_helper(left, s, i-1);
            
            vector<TreeNode *> right;
            tree_helper(right, i+1, e);
            
            for(int p = 0; p < left.size(); p++){
                for(int q = 0; q < right.size(); q++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[p];
                    root->right = right[q];
                    
                    result.push_back(root);
                }
            }
        }
    }
};
