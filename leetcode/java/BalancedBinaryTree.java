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
    public boolean isBalanced(TreeNode root) {
        return bh(root) != -1;
    }
    
    private int bh(TreeNode root) {
        if(root == null) return 0;
        
        int l = bh(root.left);
        if(l == -1) return -1;
        
        int r = bh(root.right);
        if(r == -1) return -1;
        
        if(Math.abs(l-r) <= 1) return Math.max(l, r) + 1;
        return -1;
    }
}
