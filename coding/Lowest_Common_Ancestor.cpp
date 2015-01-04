/**
 * Link: http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-i.html
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/**
 * We traverse from the bottom, and once we reach a node which matches one of the two nodes, we pass it up to its parent. 
 * The parent would then test its left and right subtree if each contain one of the two nodes. 
 *     - If yes, then the parent must be the LCA and we pass its parent up to the root. 
 *     - If not, we pass the lower node which contains either one of the two nodes (if the left or right subtree contains either p or q), 
 *               or NULL (if both the left and right subtree does not contain either p or q) up.
 */
TreeNode *LCA(TreeNode *root, int x, int y){
    if(!root) return nullptr;
    if(root->val == x || root->val == y) return root;

    TreeNode *left = LCA(root->left, x, y);
    TreeNode *right = LCA(root->right, x, y);

    if(left && right) return root;
    return left? left : right;
}
