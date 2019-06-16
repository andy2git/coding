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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (q == null && p == null) return true;
        else if (q != null && p != null) return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        else return false;
    }
}
