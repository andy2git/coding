/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode root) {
        if(root == null) return null;
        
        Map<UndirectedGraphNode, UndirectedGraphNode> nodeMap = new HashMap<>();
        Deque<UndirectedGraphNode> st = new ArrayDeque<>();
        st.push(root);
        UndirectedGraphNode nGraph = new UndirectedGraphNode(root.label);
        nodeMap.put(root, nGraph);
        
        while(!st.isEmpty()){
            UndirectedGraphNode t = st.pop();
            for(UndirectedGraphNode n : t.neighbors){
                if(!nodeMap.containsKey(n)){
                    UndirectedGraphNode nn = new UndirectedGraphNode(n.label);
                    // n node has not been explored yet
                    st.push(n);
                    nodeMap.put(n, nn);
                }
                //edge copy
                nodeMap.get(t).neighbors.add(nodeMap.get(n));
            }
        }
        
        return nGraph;
    }
}
