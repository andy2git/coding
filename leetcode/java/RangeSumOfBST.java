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
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;

        if (root.val >= L && root.val <= R) {
            return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
        } else if (root.val < L) {
            return rangeSumBST(root.right, L, R);
        } else {
            return rangeSumBST(root.left, L, R);
        }
    }
}

// implement the code in an iterative way. Follow the similar idea like in-order traveral? However controling the stop condition 
// in-order traveral is a little tricky. Actually any type of traversal is fine, we just need to skip certain branches
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;

        Deque<TreeNode> st = new ArrayDeque<>();
        int sum = 0;
        st.push(root);
        while (!st.isEmpty()) {
            TreeNode t = st.pop();
            if (t.val >= L && t.val <= R) {
                sum += t.val;
                if (t.left != null) st.push(t.left);
                if (t.right != null) st.push(t.right);
            }
            if (t.val < L && t.right != null) st.push(t.right);
            if (t.val > R && t.left != null) st.push(t.left);
        }
        return sum;
    }
}
