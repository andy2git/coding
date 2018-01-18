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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder == null || postorder == null) return null;
        
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        
        return bth(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1, map);
    }
    
    private TreeNode bth(int[] inorder, int l, int h, int[] postorder, int s, int e, Map<Integer, Integer> map) {
        if(l > h || s > e) return null;
        if(l == h || s == e) return new TreeNode(postorder[s]);
        
        int k = map.get(postorder[e]);
        TreeNode root = new TreeNode(postorder[e]);
        root.left = bth(inorder, l, k-1, postorder, s, s+k-l-1, map);
        root.right = bth(inorder, k+1, h, postorder, s+k-l, e-1, map);
        return root;
    }
}
