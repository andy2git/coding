/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */

/* Graph is assumed to be connected, and can be reached through DFS/BFS */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null) return null;
        
        UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
        Map<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<>();
        map.put(node, newNode);
        
        Queue<UndirectedGraphNode> queue = new ArrayDeque<>();
        queue.offer(node);
        while(!queue.isEmpty()) {
            UndirectedGraphNode x = queue.poll();
            for(UndirectedGraphNode nb : x.neighbors) {
                if(!map.containsKey(nb)) {
                    UndirectedGraphNode y = new UndirectedGraphNode(nb.label);
                    map.put(nb, y);
                    queue.offer(nb);
                }
                map.get(x).neighbors.add(map.get(nb));
            }
        }
        return newNode;
    }
}


// DFS
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        
        Deque<Node> st = new ArrayDeque<>();
        Map<Node, Node> m = new HashMap<>();
        st.push(node);
        m.put(node, new Node(node.val));
        
        while(!st.isEmpty()) {
            Node x = st.pop();
            for(Node t : x.neighbors){
                if(!m.containsKey(t)) {
                    Node p = new Node(t.val);
                    m.put(t, p);
                    st.push(t);
                }
                m.get(x).neighbors.add(m.get(t));
            }
        }
        return m.get(node);
    }
}
