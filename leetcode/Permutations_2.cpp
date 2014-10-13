class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if(num.empty()) return vector<vector<int>>();
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        vector<int> sofar;
        permute_helper(result, sofar, num);
        
        return result;
    }
private:
    void permute_helper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        for(int i = 0; i < rest.size(); i++){
            // remove the duplication
            if(i > 0 && rest[i] == rest[i-1]) continue;
            int t = rest[i];
            
            sofar.push_back(t);
            auto it = rest.erase(rest.begin()+i);
            
            permute_helper(result, sofar, rest);
            
            sofar.pop_back();
            rest.insert(it, t);
        }
    }
};
