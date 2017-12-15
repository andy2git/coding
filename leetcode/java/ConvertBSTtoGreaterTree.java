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
    private int sum = 0;
    public TreeNode convertBST(TreeNode root) {
        reverseInOrder(root);
        return root;
    }
    
    private void reverseInOrder(TreeNode root) {
        if(root == null) return;
        reverseInOrder(root.right);
        root.val += sum;
        sum = root.val;
        reverseInOrder(root.left);
    }
}

class Solution {
    
    public TreeNode convertBST(TreeNode root) {
        if(root == null) return root;
        
        Deque<TreeNode> st = new ArrayDeque<>();
        TreeNode p = root;
        int sum = 0;
        while(p != null || !st.isEmpty()) {
            if(p != null) {
                st.push(p);
                p = p.right;
            }else {
                p = st.pop();
                p.val += sum;
                sum = p.val;
                p = p.left;
            }
        }
        return root;
    }
}
