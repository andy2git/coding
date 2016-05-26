/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param A: an integer array
     * @return: a tree node
     */
    public TreeNode sortedArrayToBST(int[] A) {
        int n = A.length;
        if(n == 0) return null;
        
        return sortedArrayToBSTHelper(A, 0, n-1);
    }
    
    private TreeNode sortedArrayToBSTHelper(int[] A, int s, int e){
        if(e < s) return null;
        if(e == s) return new TreeNode(A[s]);
        
        int mid = s + (e-s)/2;
        TreeNode root = new TreeNode(A[mid]);
        root.left = sortedArrayToBSTHelper(A, s, mid-1);
        root.right = sortedArrayToBSTHelper(A, mid+1, e);
        
        return root;
    }
}

