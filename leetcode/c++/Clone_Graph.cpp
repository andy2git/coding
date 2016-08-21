/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 *
 * 
 * Solution: this clone is based on the edge instead of the node. 
 *           This way will make sure the edge will be copied to the
 *           cloned graph as well.
 *
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        stack<UndirectedGraphNode *> st;
        UndirectedGraphNode *t = nullptr;
        UndirectedGraphNode *nGraph = new UndirectedGraphNode(node->label);
        map[node] = nGraph;
        
        st.push(node);
        while(!st.empty()){
            t = st.top();
            st.pop();
            
            for(int i = 0; i < t->neighbors.size(); i++){
                UndirectedGraphNode *nb = t->neighbors[i];
                if(map.find(nb) == map.end()){
                    UndirectedGraphNode *x = new UndirectedGraphNode(nb->label);
                    map[nb] = x;
                    st.push(nb);
                }
                
                map[t]->neighbors.push_back(map[nb]);
            }
        }
        
        return nGraph;
    }
};


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 * 
 * 
 * BFS based solution.
 * It is almost identical to the DFS solution except the order of edge copying is different from DFS.
 * DFS will make go deeper and deeper, while BFS will copy edges layer by layer.
 *
 * Every time a node is pushed into queue, its clone is created. Also their mapping relationship is
 * kept in map<UndirectedGraphNode *, UndirectedGraphNode *> to clone edge later.
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        queue<UndirectedGraphNode *> queue;
        UndirectedGraphNode *t = nullptr;
        UndirectedGraphNode *nGraph = new UndirectedGraphNode(node->label);
        map[node] = nGraph;
        
        queue.push(node);
        while(!queue.empty()){
            t = queue.front();
            queue.pop();
            
            for(int i = 0; i < t->neighbors.size(); i++){
                UndirectedGraphNode *nb = t->neighbors[i];
                if(map.find(nb) == map.end()){
                    UndirectedGraphNode *x = new UndirectedGraphNode(nb->label);
                    map[nb] = x;
                    queue.push(nb);
                }
               
                // for each edge, clone a copy on the new graph 
                map[t]->neighbors.push_back(map[nb]);
            }
        }
        
        return nGraph;
    }
};
