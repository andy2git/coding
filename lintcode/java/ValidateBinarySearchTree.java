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
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        if(root.left == null && root.right == null) return true;
        
        return isValidBSTHelper(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private boolean isValidBSTHelper(TreeNode root, int l, int h){
        if(l > h) throw new IllegalArgumentException("xxx");
        
        if(root == null) return true;
        if(root.val <=l || root.val >= h) return false;
        return isValidBSTHelper(root.left, l, root.val) && isValidBSTHelper(root.right, root.val, h);
    }

    // Solution#2: bottom-up return (min, max) seen so far
}
