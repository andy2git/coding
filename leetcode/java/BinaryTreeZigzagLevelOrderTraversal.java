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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null) return Collections.emptyList();

        // switch between two stacks
        Deque<TreeNode> p = new ArrayDeque<>();
        p.push(root);
        
        Deque<TreeNode> q = new ArrayDeque<>();
        boolean flag = true;
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();

        while(!p.isEmpty()) {
            TreeNode t = p.pop();
            list.add(t.val);
            pushToStack(t, q, flag);
            if(p.isEmpty()) {
                result.add(new ArrayList<>(list));
                list.clear(); 
                flag = !flag;
                Deque<TreeNode> k = p;
                p = q;
                q = k;
            }
        }
        return result;
    }
    
    private void pushToStack(TreeNode t, Deque<TreeNode> q, boolean flag) {
        if(flag) {
            if(t.left != null) q.push(t.left);
            if(t.right != null) q.push(t.right);
        } else {
            if(t.right != null) q.push(t.right);
            if(t.left != null) q.push(t.left);
        }
    }
}
