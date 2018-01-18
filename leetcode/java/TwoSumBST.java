/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        if(root == null) return false;
        
        return fth(root, root, k);
    }
    
    private boolean fth(TreeNode root, TreeNode node, int k) {
        if(node == null) return false;
        int t = k - node.val;
        TreeNode n = search(root, t);
        if(n != null && n != node) return true;
        else return fth(root, node.left, k) || fth(root, node.right, k);
    }
    
    private TreeNode search(TreeNode root, int t) {
        if(root == null) return null;
        if(root.val == t) return root;
        else if(root.val < t) return search(root.right, t);
        else return search(root.left, t);
    }
}
