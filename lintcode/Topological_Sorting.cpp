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
        // write your code here
        if(graph.empty()) return {};
        
        unordered_map<DirectedGraphNode *, int> degree;
        fillDegree(degree, graph);
        
        vector<DirectedGraphNode *> result;
        while(!degree.empty()){
            DirectedGraphNode *t = findFirstNZN(degree);
            if(t == nullptr) throw runtime_error("no topological order exist!");
            
            result.push_back(t);
            
            for(int i = 0; i < t->neighbors.size(); i++){
                degree[t->neighbors[i]]--;
            }
            degree.erase(t);
        }
        
        return result;
    }
    
private:
    void fillDegree(unordered_map<DirectedGraphNode *, int> &degree, vector<DirectedGraphNode *> &graph){
        for(int i = 0; i < graph.size(); i++){
            DirectedGraphNode *t = graph[i];
            if(degree.find(t) == degree.end()) degree[t] = 0;
            
            for(int j = 0; j < t->neighbors.size(); j++){
                degree[t->neighbors[j]]++;
            }
        }
    }
    
    DirectedGraphNode* findFirstNZN(unordered_map<DirectedGraphNode *, int> &degree){
        for(auto it = degree.begin(); it != degree.end(); ++it){
            if(it->second == 0) return it->first;
        }
        
        return nullptr;
    }
};


