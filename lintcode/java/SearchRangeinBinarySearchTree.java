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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    public ArrayList<Integer> searchRange(TreeNode root, int k1, int k2) {
        if(k1 > k2) throw new IllegalArgumentException("xxx");
        
        if(root == null) return new ArrayList<>();
        
        ArrayList<Integer> ret = new ArrayList<>();
        Deque<TreeNode> st = new ArrayDeque<>();
        st.push(root);
        while(!st.isEmpty()){
            TreeNode t = st.pop();
            if(t.val < k1) {
                if(t.right != null) st.push(t.right);
            } else if(t.val > k2){
                if(t.left != null) st.push(t.left);
            }else{
                ret.add(t.val);   
                if(t.left != null) st.push(t.left);
                if(t.right != null) st.push(t.right);
            }
        }
        
        Collections.sort(ret);
        return ret;
    }
}
