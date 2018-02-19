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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null) return Collections.emptyList();
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        
        Queue<TreeNode> p = new ArrayDeque<>();
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> layer = new ArrayList<>();
        
        while(!q.isEmpty()) {
            TreeNode t = q.poll();
            layer.add(t.val);
            if(t.left != null) p.offer(t.left);
            if(t.right != null) p.offer(t.right);
            if(q.isEmpty()) {
                Queue<TreeNode> k = q;
                q = p;
                p = k;
                result.add(new ArrayList<>(layer));
                layer.clear();
            }
        }
        Collections.reverse(result);
        return result;
    }
}
