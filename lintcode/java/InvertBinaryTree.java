/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return null;
        if(root.left == null && root.right == null) return root;
        
        TreeNode left = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(left);
        return root;
    }

    // solution #2: tree traversal
    public void invertBinaryTree(TreeNode root) {
        if(root == null) return;
        if(root.left == null && root.right == null) return;
        
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        
        while(!queue.isEmpty()){
            TreeNode t = queue.poll();
            swapChild(t);
            if(t.left != null) queue.offer(t.left);
            if(t.right != null) queue.offer(t.right);
        }
        
        return;
    }
    
    private void swapChild(TreeNode t){
        TreeNode tmp = t.left;
        t.left = t.right;
        t.right = tmp;
    }
}
