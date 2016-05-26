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
     * @param root: The root of binary tree.
     * @return: Inorder in ArrayList which contains node values.
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) return Collections.emptyList();
        
        List<Integer> leftSide = inorderTraversal(root.left);
        List<Integer> rightSide = inorderTraversal(root.right);
        
        List<Integer> result = new ArrayList<>();
        result.addAll(leftSide);
        result.add(root.val);
        result.addAll(rightSide);
        return Collections.unmodifiableList(result);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) return Collections.emptyList();
        
        Deque<TreeNode> st = new ArrayDeque<>();
        TreeNode p = root;
        
        List<Integer> result = new ArrayList<>();
        while(p != null || !st.isEmpty()){
            if(p != null){
                st.push(p);
                p = p.left;
            }else{
                TreeNode t = st.pop();
                // Precondition check to make st.pop() is not empty
                // It is guaranteed through while condition though.
                result.add(t.val);
                p = t.right;
            }
        }
        return result;
    }
}
