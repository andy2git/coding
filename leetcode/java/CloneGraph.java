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
