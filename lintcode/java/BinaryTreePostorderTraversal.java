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
     * @return: Postorder in ArrayList which contains node values.
     */
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return Collections.emptyList();
        
        List<Integer> result = new ArrayList<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        
        while(!stack.isEmpty()){
            TreeNode t = stack.pop();
            result.add(t.val);
            
            if(t.left != null) stack.push(t.left);
            if(t.right != null) stack.push(t.right);
        }
        
        Collections.reverse(result);
        return result;
    }
}
