/* Time Limit Exceeded */
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        
        vector<int> factor(candidates.size());
        for(int i = 0; i < candidates.size(); i++){
            factor[i] = target/candidates[i];
        }
        
        combine_helper(result, factor, candidates, 0, target, vector<int>());

        return result;
    }
private:
    void combine_helper(vector<vector<int>> &result, vector<int> &factor, vector<int> &candidates, int s, int target, vector<int> sofar){
        if(target == 0){
            result.push_back(sofar);
            return;
        }
        
        if(s >= factor.size()){
            return;
        }
        
        for(int i = 0; i <= factor[s]; i++){
            if(i > 0) {
                sofar.push_back(candidates[s]);
                target -= candidates[s];
                if(target < 0) break;
            }
            combine_helper(result, factor, candidates, s+1, target, sofar);
        }
    }

};
