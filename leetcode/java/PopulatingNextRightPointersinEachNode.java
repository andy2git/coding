/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        
        Queue<Node> p = new ArrayDeque<>();
        Queue<Node> q = new ArrayDeque<>();
        Node pre = null;
        
        p.offer(root);
        while(!p.isEmpty()) {
            Node t = p.poll();
            if(t.left != null) q.offer(t.left);
            if(t.right != null) q.offer(t.right);
            if(pre != null) pre.next = t;
            pre = t;
            
            if(p.isEmpty()) {
                Queue<Node> k = p;
                p = q;
                q = k;
                pre = null;
            }
        }
        return root;
    }
}
