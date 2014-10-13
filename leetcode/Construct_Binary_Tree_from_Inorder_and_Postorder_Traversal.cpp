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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty()) return nullptr;
        if(inorder.size() == 1 && postorder.size() == 1) return new TreeNode(inorder[0]);
        
        unordered_map<int, int> map;
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return build_tree_helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, map);
    }
private:
    TreeNode *build_tree_helper(vector<int> &A, int l, int h, vector<int> &B, int s, int e, unordered_map<int, int> &map){
        if(l > h || s > e) return nullptr;
        
        int k = map[B[e]] - l;
        TreeNode *root = new TreeNode(B[e]);
        root->left = build_tree_helper(A, l, l+k-1, B, s, s+k-1, map);
        root->right = build_tree_helper(A, l+k+1, h, B, s+k, e-1, map);
        
        return root;
    }
};
