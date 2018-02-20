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
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null) return Collections.emptyList();
        
        TreeNode dummy = new TreeNode(0);
        Queue<TreeNode> p = new ArrayDeque<>();
        p.offer(root);
        p.offer(dummy);
        
        List<Integer> result = new ArrayList<>();
        int right = 0;
        while(!p.isEmpty()) {
            TreeNode t = p.poll();
            if(t != dummy) {
                right = t.val;
                if(t.left != null) p.offer(t.left);
                if(t.right != null) p.offer(t.right);
            }else {
                if(!p.isEmpty()) p.offer(dummy);
                result.add(right);
            }
        }
        return result;
    }
}
