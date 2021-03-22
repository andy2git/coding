/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    private final Deque<TreeNode> stack = new ArrayDeque<>();
    private TreeNode p;

    public BSTIterator(TreeNode root) {
        p = root;
        while(p != null){
            stack.push(p);
            p = p.left;
        }
    }
    
    

    /** @return whether we have a next smallest number */
    public boolean hasNext() {

        return !stack.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode t = stack.pop();
        if(t.right != null) {
            p = t.right;
            while(p != null){
                stack.push(p);
                p = p.left;
            }
        }
        return t.val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
