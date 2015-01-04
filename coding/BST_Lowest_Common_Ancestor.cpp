#include <algorithm>
#include <stdexcept>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){};
};

// 
// -----x----y-------
// 
// Assume x and y are included in the Binary search tree

int bst_lca_recursive(TreeNode *root, int x, int y){
    if(!root) throw runtime_error("should not happen!");
    
    int min = std::min(x, y);
    int max = std::max(x, y);
    
    if(root->val < min) return bst_lca_recursive(root->right, x, y);
    else if(root->val > max) return bst_lca_recursive(root->left, x, y);
    else return root->val;
}

int bst_lca_iterative(TreeNode *root, int x, int y){
    if(!root) throw runtime_error("should not happen!");
    
    int min = std::min(x, y);
    int max = std::max(x, y);
    
    while(root){
        if(root->val > max) root = root->left;
        else if(root->val < min) root = root->right;
        else return root->val;
    }
    
    return -1;
}


