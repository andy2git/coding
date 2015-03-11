/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        unordered_map<DirectedGraphNode *, int> dMap;
        fillDegreeMap(dMap, graph);
        
        vector<DirectedGraphNode *> result;
        vector<DirectedGraphNode *> zd;
        
        findFirstZDN(dMap, zd);
        while(zd.size() > 0){
            DirectedGraphNode *t = zd.back();
            result.push_back(t);
            zd.pop_back();
            
            for(auto ng : t->neighbors){
                dMap[ng]--;
                if(dMap[ng] == 0) zd.push_back(ng);
            }
        }
        
        return result;
    }
private:
    void fillDegreeMap(unordered_map<DirectedGraphNode *, int> &dMap, vector<DirectedGraphNode *> &graph){
        for(int i = 0; i < graph.size(); i++){
            DirectedGraphNode *x = graph[i];
            if(dMap.find(x) == dMap.end()){
                dMap[x] = 0;
            }
            
            for(auto ng: x->neighbors){
                if(dMap.find(ng) == dMap.end()){
                    dMap[ng] = 1;
                }else{
                    dMap[ng]++;
                }
            }
        }
    }
    
    void findFirstZDN(unordered_map<DirectedGraphNode *, int> &dMap, vector<DirectedGraphNode *> &zd){
        for(auto it = dMap.begin(); it != dMap.end(); ++it){
            if(it->second == 0) zd.push_back(it->first);
        }
    }
};
