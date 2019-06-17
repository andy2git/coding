/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// This solution needs to traverse the left subtree everytime we need to combine the result.
// So it might get slow
class Solution {
    public TreeNode increasingBST(TreeNode root) {
        if(root == null) return root;
        if(root.left == null && root.right == null) return root;
        
        if(root.right != null) root.right = increasingBST(root.right);
        
        if(root.left != null) {
            TreeNode left = increasingBST(root.left);
            TreeNode p = left;
            while(p.right != null) p = p.right;
            p.right = root;
            return left;
        } else {
            return root;
        }   
    }
}

// In order traverse solution
class Solution {
    private final TreeNode dummy = new TreeNode(0);
    private TreeNode p = dummy;
    public TreeNode increasingBST(TreeNode root) {
        inorder(root);
        return dummy.right;
    }
    
    private void inorder(TreeNode root) {
        if(root == null) return;
        
        inorder(root.left);
        p.right = root;
        root.left = null;
        p = p.right;
        inorder(root.right);
    }
}
