class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> sofar;
        combinationSumHelper(result, sofar, target, candidates, 0);
        return result;
    }
private:
    void combinationSumHelper(vector<vector<int>> &result, vector<int> &sofar,
        int target, vector<int> &remain, int s){
            
        int sum = accumulate(sofar.begin(), sofar.end(), 0);    
        if(sum == target) {
            result.push_back(sofar);
            return;
        }
        if(s == remain.size() || sum > target) return;
        
        int k = 0;
        int x = remain[s];
        while(sum + k*x <= target){
            if(k > 0) sofar.push_back(x);
            combinationSumHelper(result, sofar, target, remain, s+1);
            k++;
        }
        
        //restore sofar
        while(k > 1){
            sofar.pop_back();
            k--;
        }
    }
};
