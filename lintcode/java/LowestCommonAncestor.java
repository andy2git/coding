/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        if(root == null || A == null || B == null) return null;
        if(root == A || root == B) return root;
        
        TreeNode l = lowestCommonAncestor(root.left, A, B);
        TreeNode r = lowestCommonAncestor(root.right, A, B);
        
        if(l == null) return r;
        if(r == null) return l;
        
        // first node with l != null && r != null
        // otherwise, the LCA node will be returned all the way to the top
        // NOTES:
        // 1. left or right subtree returns null
        // 2. left and right subtree does not return null
        return root;
    }
}
