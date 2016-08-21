class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if(num.empty()) return vector<vector<int>>();
        vector<vector<int>> result;
        
        vector<int> sofar;
        vector<int> rest;
        permute_helper(result, sofar, num);
        
        return result;
    }
    
private:
    // sofar and rest can be passed by reference to avoid unnecessary
    void permute_helper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        for(int i = 0; i < rest.size(); i++){
            int t = rest[i];
            sofar.push_back(t);
            auto it = rest.erase(rest.begin()+i);
            permute_helper(result, sofar, rest);
            sofar.pop_back();
            rest.insert(it, t);
        }
    }
};
