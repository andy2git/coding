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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty()) return nullptr;
        if(num.size() == 1) return new TreeNode(num[0]);
        
        return bst_helper(num, 0, num.size()-1);
    }
 private:   
    TreeNode *bst_helper(vector<int> &A, int l, int h){
        if(l > h) return nullptr;
        
        int m = l + (h-l)/2;
        TreeNode *root = new TreeNode(A[m]);
        root->left = bst_helper(A, l, m-1);
        root->right = bst_helper(A, m+1, h);
        
        return root;
    }
};
