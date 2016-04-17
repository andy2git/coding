/**
 * Solution: find the first element which has non empty left and right returned
 *  - top->down: search the element, and return the node has A or B
 *  - bottom->up: based on the searched result to return the FIRST node with non-empty left or right return
 * 
 *    5 <- A
 *     \
 *      6 <- B
 *  if A or B are the LCA itself, it works as well.
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(!root) return nullptr;
        if(root == A || root == B) return root;
        
        TreeNode *l = lowestCommonAncestor(root->left, A, B);
        TreeNode *r = lowestCommonAncestor(root->right, A, B);
        
        if(!l) return r;
        if(!r) return l;
        return root;
    }
};
