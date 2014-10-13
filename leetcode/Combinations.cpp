class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> nums;
        
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        
        vector<vector<int>> result;
        combine_helper(result, vector<int>(), nums, k);
        return result;
    }
    
private:
    void combine_helper(vector<vector<int>> &result, vector<int> sofar, vector<int> rest, int k){
        if(sofar.size() == k){
            result.push_back(sofar);
            return;
        }
        if(rest.empty()) return;
        
        int x = 0;
        if(sofar.empty()) x = 0;
        else x = sofar[sofar.size()-1];
        
        while(!rest.empty() && rest[0] < x){
            rest.erase(rest.begin());
        }
        
        while(!rest.empty()){
            sofar.push_back(rest[0]);
            rest.erase(rest.begin());
            combine_helper(result, sofar, rest, k);
            sofar.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        combine_helper(result, vector<int>(), n, 1, k);
        return result;
    }
    
private:
    void combine_helper(vector<vector<int>> &result, vector<int> sofar, int n, int s, int k){
        if(k == 0){
            result.push_back(sofar);
            return;
        }
        
        for(int i = s; i <= n; i++){
            sofar.push_back(i);
            combine_helper(result, sofar, n, i+1, k-1);
            sofar.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> t;
        combine_helper(result, t, n, 1, k);
        return result;
    }
    
private:
    void combine_helper(vector<vector<int>> &result, vector<int> &sofar, int n, int s, int k){
        if(k == 0){
            result.push_back(sofar);
            return;
        }
        
        for(int i = s; i <= n; i++){
            sofar.push_back(i);
            combine_helper(result, sofar, n, i+1, k-1);
            sofar.pop_back();
        }
    }
};
