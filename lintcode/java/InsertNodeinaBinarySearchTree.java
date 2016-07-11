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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    public TreeNode insertNode(TreeNode root, TreeNode node) {
        if(root == null) return node;
        
        TreeNode p = root;
        while(p != null){
            if(node.val > p.val){
                // trick like we did linked list
                if(p.right == null){
                    p.right = node;
                }else {
                    p = p.right;
                }
            }else if (node.val < p.val){
                // trick like we did linked list
                if(p.left == null){
                    p.left = node;
                }else {
                    p = p.left;
                }
            } else {
                break;
            }
        }
        return root;
    }
}
