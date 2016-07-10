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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    public boolean isBalanced(TreeNode root) {
        return isBalancedHelper(root) >= 0;
    }
    
    private int isBalancedHelper(TreeNode root){
        if(root == null) return 0;
        if(root.left == null && root.right == null) return 1;
        
        int l = isBalancedHelper(root.left);
        if(l < 0) return -1;
        
        int r = isBalancedHelper(root.right);
        if(r < 0) return -1;
        
        if(Math.abs(l-r) <= 1) return Math.max(l, r) + 1;
        else return -1;
    }
}
