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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        if(preorder.size() == 1 && inorder.size() == 1) return new TreeNode(preorder[0]);
        
        unordered_map<int, int> map;
        for(int i = 0; i <inorder.size(); i++){
            map[inorder[i]] = i;
        }
        
        return tree_helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
    }
private:
    TreeNode *tree_helper(vector<int> &A, int l, int h, vector<int> &B, int s, int e, unordered_map<int, int> &map){
        if(l > h || s > e) return nullptr;
        
        int k = map[A[l]]-s;
        
        TreeNode *root = new TreeNode(A[l]);
        root->left = tree_helper(A, l+1, l+k, B, s, s+k-1, map);
        root->right = tree_helper(A, l+k+1, h, B, s+k+1, e, map);
        
        return root;
    }
};
