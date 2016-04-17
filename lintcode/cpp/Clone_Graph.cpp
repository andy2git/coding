/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(!node) return nullptr;
        
        UndirectedGraphNode *cGraph = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        map[node] = cGraph;
        
        stack<UndirectedGraphNode *> st;
        st.push(node);
        
        while(!st.empty()){
            UndirectedGraphNode *t = st.top();
            st.pop();
            
            for(int i = 0; i < (t->neighbors).size(); i++){
                UndirectedGraphNode *p = t->neighbors[i];
                if(map.find(p) == map.end()){
                    // copy nodes
                    UndirectedGraphNode *q = new UndirectedGraphNode(p->label);
                    map[p] = q;
                    st.push(p);
                }
                
                // copy edges
                map[t]->neighbors.push_back(map[p]);
            }    
        }
        
        return cGraph;
        
    }
};
