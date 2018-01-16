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
    public List<String> binaryTreePaths(TreeNode root) {
        if(root == null) return Collections.emptyList();
        List<String> result = new ArrayList<>();
        btph(result, "", root);
        return result;
    }
    
    private void btph(List<String> result, String sofar, TreeNode node) {
        if(node == null) return;
        if(node.left == null && node.right == null) {
            sofar = path(sofar, node);
            result.add(sofar);
            return;
        }
        
        sofar = path(sofar, node);
        
        btph(result, sofar, node.left);
        btph(result, sofar, node.right);
    }
    
    private String path(String sofar, TreeNode node) {
        if(sofar.isEmpty()) return String.valueOf(node.val);
        else return sofar + "->" + node.val;
    }
}
