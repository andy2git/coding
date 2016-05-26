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
     * @return: Preorder in ArrayList which contains node values.
     */
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null) return Collections.emptyList();
        
        Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
        stack.push(root);
        
        List<Integer> results = new ArrayList<>();
        while(!stack.isEmpty()) {
            TreeNode t = stack.pop();
            results.add(t.val);
            if(t.right != null) stack.push(t.right);
            if(t.left != null) stack.push(t.left);
        }
        
        return Collections.unmodifiableList(results);
    }
}
