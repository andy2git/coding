/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/* If one of the nodes (p or q) does not exist in the tree, then it is hard to differentiate
  between this case with the following one.
   p
  /
 q
*/
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if(root == p || root == q) return root;
        
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        // left == null and right == null could mean two things:
        // 1. found p or q => does mattter which one to return
        // 2. found lca(p, q) => return the found element
        if(left == null) return right;
        if(right == null) return left;
        return root;
    }
}
