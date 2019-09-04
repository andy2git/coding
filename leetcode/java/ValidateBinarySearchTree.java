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
    public boolean isValidBST(TreeNode root) {
        return isBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    // use long for [left, right] to make sure we can use Integer.MIN_VALUE AND Integer.MAX_VALUE for node value
    // the other option is to Intege, null
    private boolean isBST(TreeNode root, long left, long right) {
        if(root == null) return true;
        
        return root.val > left && root.val < right 
            && isBST(root.left, left, root.val)
            && isBST(root.right, root.val, right);
    }
}

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
    public boolean isValidBST(TreeNode root) {
        return isBST(root, null, null);
    }
    
    private boolean isBST(TreeNode root, Integer left, Integer right) {
        if(root == null) return true;
        
        return greater(root.val, left) && less(root.val, right) 
            && isBST(root.left, left, root.val)
            && isBST(root.right, root.val, right);
    }
    
    private boolean greater(int x, Integer y){
        if(y == null) return true;
        else return x > y;
    }
    
    private boolean less(int x, Integer y){
        if(y == null) return true;
        else return x < y;
    }
}
