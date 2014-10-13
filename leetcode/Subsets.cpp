class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.empty()) return vector<vector<int>>();
        
        vector<vector<int>> result;
        vector<int> t;
        
        sort(S.begin(), S.end());
        subset_helper(result, t, S);
        
        return result;
    }
    
    void subset_helper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        int x = rest[0];
        auto it = rest.erase(rest.begin());
        subset_helper(result, sofar, rest);
        
        sofar.push_back(x);
        subset_helper(result, sofar, rest);
        //recover the rest back 
        rest.insert(it, x);
    }
};
