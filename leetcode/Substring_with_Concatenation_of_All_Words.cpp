class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if(L.empty()) return {-1};
        
        vector<int> result;
        unordered_map<string, int> map;
        
        for(int i = 0; i < L.size(); i++){
            map[L[i]]++;
        }
        
        int len = L.size() * L[0].size();
        string st;
        for(int i = 0; i <= (int)S.size() - len; i++){
            st = S.substr(i, len);
            if(is_composition(map, st)){
                result.push_back(i);
            }
        }
        
        return result;
    }
    
private:
    bool is_composition(unordered_map<string, int> &map, string &s){
        int window = map.begin()->first.size();
        unordered_map<string, int> match;
        
        string t;
        for(int i = 0; i < s.size(); i += window){
            t = s.substr(i, window);
            if(map.find(t) == map.end()){
                return false;
            }else{
                match[t]++;
                // if the elements did not cover all the elements in 
                // the map, then one of the entry will exceed for sure.
                if(match[t] > map[t]) return false;
            }
        }
        
        return true;
    }
};
