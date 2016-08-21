class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if(candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> sofar;
        comb_sum_helper(result, sofar, 0, target, candidates);
        
        return result;
    }
private:
    void comb_sum_helper(vector<vector<int>> &result, vector<int> &sofar, int sum, int target, vector<int> &remain){
        if(sum == target){
            result.push_back(sofar);
            return;
        }
        
        if(remain.empty()) return;
        
        int t = remain[0];
        remain.erase(remain.begin());
        
        comb_sum_helper(result, sofar, sum, target, remain);
        
        int i = 1;
        while(sum + i*t <= target){
            sofar.push_back(t);
            comb_sum_helper(result, sofar, sum + i*t, target, remain);    
            i++;
        }
        
        //recover from options
        while(i > 1) {
            sofar.pop_back();
            i--;
        }
        remain.insert(remain.begin(), t);
    }
};
