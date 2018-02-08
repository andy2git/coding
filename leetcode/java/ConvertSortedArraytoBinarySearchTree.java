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
    public TreeNode sortedArrayToBST(int[] nums) {
        return stbh(nums, 0, nums.length-1);
    }
    
    private TreeNode stbh(int[] A, int s, int e) {
        if(s > e) return null;
        if(s == e) return new TreeNode(A[s]);
        
        int m = s + (e-s)/2;
        TreeNode root = new TreeNode(A[m]);
        root.left = stbh(A, s, m-1);
        root.right = stbh(A, m+1, e);
        return root;
    }
}
