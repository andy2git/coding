class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        combinationSumHelper(result, {}, target, num, 0);   
        return result;
    }
    
private:
    void combinationSumHelper(vector<vector<int>> &result, vector<int> sofar,
        int target, vector<int> &remain, int s){ 
     
        int sum = accumulate(sofar.begin(), sofar.end(), 0);    
        if(sum == target) {
            result.push_back(sofar);
            return;
        }   
        if(s == remain.size()) return;
        
        int k = s;
        while(s < remain.size()-1 && remain[s] == remain[s+1]) s++;
        int x = remain[k];
        
        combinationSumHelper(result, sofar, target, remain, s+1);
        
        for(int i = k; i <= s; i++){
            if(sum + (i-k+1)*x <= target){
                sofar.push_back(x);
                combinationSumHelper(result, sofar, target, remain, s+1);
            }   
        }
    } 
};


