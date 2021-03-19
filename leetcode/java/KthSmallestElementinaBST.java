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


// Solution#2
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        if(root == null) throw new IllegalArgumentException("x");
        
        Deque<TreeNode> st = new ArrayDeque<>();
        while(root != null || !st.isEmpty()) {
            if(root != null) {
                st.push(root);
                root = root.left;
            }else{
                TreeNode t = st.pop();
                k--;
                if(k == 0) return t.val;
                root = t.right;
            }
        }
        
        throw new IllegalArgumentException("x");
    }
}

//Solution#3 Recursive version of Solution #2
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        inorder(root, k);
        return result;
    }
    
    private int cnt = 0;
    private int result = 0;
    private void inorder(TreeNode root, int k) {
        if(root == null) return;
        inorder(root.left, k);
        cnt++;
        if(cnt == k) {
            result = root.val;
            return;
        }
        inorder(root.right, k);
    }
}
