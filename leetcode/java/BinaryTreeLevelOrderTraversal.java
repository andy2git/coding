/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/* Solution #1 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null) return Collections.emptyList();
        
        TreeNode d = new TreeNode(1);
        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        q.offer(d);
        
        List<Integer> layer = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        while(!q.isEmpty()) {
            TreeNode t = q.poll();
            if(t != d) {
                layer.add(t.val);
                if(t.left != null) q.offer(t.left);
                if(t.right != null) q.offer(t.right);
            }else{
                if(!q.isEmpty()) q.offer(d);
                result.add(layer);
                layer = new ArrayList<>();
            }
        }
        return result;
    }
}

/* Solution #2 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null) return Collections.emptyList();
        Queue<TreeNode> p = new ArrayDeque<>();
        Queue<TreeNode> q = new ArrayDeque<>();
        p.offer(root);

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> layer = new ArrayList<>();
        while(!p.isEmpty()){
            TreeNode t = p.poll();
            layer.add(t.val);
            if(t.left != null) q.offer(t.left);
            if(t.right != null) q.offer(t.right);
            if(p.isEmpty()) {
                Queue<TreeNode> k = p;
                p = q;
                q = k;
                result.add(layer);
                layer = new ArrayList<>();
            }
        }
        return result;
    }
}
