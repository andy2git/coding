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
    private int cnt = 0;
    public int pathSum(TreeNode root, int sum) {
        if(root == null) return 0;
        psh(root, sum);
        return cnt;
    }
    
    private List<Integer> psh(TreeNode root, int sum) {
        if(root == null) return Collections.emptyList();
        List<Integer> list = new ArrayList<>();
        if(root.left == null && root.right == null) {
            if(root.val == sum) cnt++;
            list.add(root.val);
            return list;
        }
        
        List<Integer> left = psh(root.left, sum);
        List<Integer> right = psh(root.right, sum);
        
        for(Integer x: left) {
            if(x + root.val == sum) cnt++;
            list.add(x+root.val);
        }
        
        for(Integer x: right) {
            if(x + root.val == sum) cnt++;
            list.add(x+root.val);
        }
        if(root.val == sum) cnt++;
        list.add(root.val);
        return list;
    }
}
