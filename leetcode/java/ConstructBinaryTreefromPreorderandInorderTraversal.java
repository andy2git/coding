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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder == null && inorder == null) return null;
        
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return bth(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1, map);
    }
    
    private TreeNode bth(int[] preorder, int s, int e, int[] inorder, int l, int h, Map<Integer, Integer> map) {
        // this is needed as we do not perform index check when make recursive calls
        if(s > e || l > h) return null;
        // (s == e) should be good enough as inoder will have same length anyway
        if(s == e || l == h) return new TreeNode(preorder[s]);
        
        TreeNode root = new TreeNode(preorder[s]);
        int k = map.get(preorder[s]);
        root.left = bth(preorder, s+1, s+k-l, inorder, l, k-1, map);
        root.right = bth(preorder, s+k-l+1, e, inorder, k+1, h, map);
        return root;
    }
}
