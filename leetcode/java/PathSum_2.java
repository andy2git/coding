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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null) return Collections.emptyList();
        List<List<Integer>> result = new ArrayList<>();
        psh(result, root, new ArrayList<>(), sum);
        return result;
    }
    
    private void psh(List<List<Integer>> result, TreeNode node, List<Integer> sofar, int remain) {
        if(node == null) return;
        if(node.left == null && node.right == null) {
            if(node.val == remain) {
                sofar.add(node.val);
                result.add(new ArrayList<>(sofar));
                sofar.remove(sofar.size()-1);
            }
            return;
        }
        sofar.add(node.val);
        psh(result, node.left, sofar, remain-node.val);
        psh(result, node.right, sofar, remain-node.val);
        sofar.remove(sofar.size()-1);
    }
}
