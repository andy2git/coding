/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */



// For binary search tree, first element traversing from the root which is in [min, max] is the LCA element.
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if(root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
        else if (root.val < p.val & root.val < q.val) return lowestCommonAncestor(root.right, p, q);
        else return root;
    }
}

// Above solution is wrong. We cannot assume p.val > q.val
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        // make sure [min, max]
        int min = Math.min(p.val, q.val);
        int max = Math.max(p.val, q.val);
        
        if(root.val >= min && root.val <= max) return root;
        else if(root.val < min) return lowestCommonAncestor(root.right, p, q);
        else return lowestCommonAncestor(root.left, p, q);
    }
}
