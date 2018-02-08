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
    
    public int kthSmallest(TreeNode root, int k) {
        TreeNode t = ksh(root, k);
        return t.val;
    }
    
    private int cnt = 0;
    private TreeNode ksh(TreeNode root, int k) {
        if(root == null) return null;
        TreeNode t = ksh(root.left, k);
        if(t != null) return t;
        
        cnt++;
        if(cnt == k) return root;
        
        return ksh(root.right, k);
    }
}
