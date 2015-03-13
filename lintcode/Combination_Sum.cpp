class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if(candidates.empty()) return {};
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> sofar;
        
        combinationHelper(result, sofar, candidates, 0, target);
        return result;
    }
private:
    void combinationHelper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain, int k, int target){
        int sum = accumulate(sofar.begin(), sofar.end(), 0);
        if(sum == target) {
            result.push_back(sofar);
            return;
        }
        if(k == remain.size()) return;
        
        int x = remain[k];
        int t = 0;
        while(sum + t*x <= target){
            if(t > 0) sofar.push_back(x);
            combinationHelper(result, sofar, remain, k+1, target);
            t++;
        }
        
        while(t > 1){
            sofar.pop_back();
            t--;
        }
    }
};
