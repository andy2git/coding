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
 * Example of iterate a tree:
 * BSTIterator iterator = new BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode node = iterator.next();
 *    do something for node
 * } 
 */
public class BSTIterator {
    private final Deque<TreeNode> st = new ArrayDeque<>();
    private TreeNode p;

    public BSTIterator(TreeNode root) {
        p = root;
    }

    public boolean hasNext() {
        while (p != null) {
            st.push(p);
            p = p.left;
        }

        return !st.isEmpty();
    }

    public TreeNode next() {
        TreeNode t = st.pop();
        p = t.right;
        return t;
    }
}
