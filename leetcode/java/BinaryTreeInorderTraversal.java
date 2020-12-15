/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        inorder(root);
        return result;
    }
    
    private final List<Integer> result = new ArrayList<>();
    private void inorder(TreeNode p) {
        if(p == null) return;
        if(p.left != null) inorder(p.left);
        result.add(p.val);
        if(p.right != null) inorder(p.right);
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null) return Collections.emptyList();
        
        Deque<TreeNode> st = new ArrayDeque<>();
        TreeNode p = root;
        List<Integer> result = new ArrayList<>();
        while(p != null || !st.isEmpty()){
            if(p != null) {
                st.push(p);
                p = p.left;
            }else{
                TreeNode t = st.pop();
                result.add(t.val);
                if(t.right != null) p = t.right;
            }
        }
        return result;
    }
}
