class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        if(nums.size() == 0) return {};
        
        vector<vector<int>> result;
        vector<int> sofar;
        
        permuteHelper(result, sofar, nums);
        return result;
    }

private:
    void permuteHelper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain){
        if(remain.empty()){
            result.push_back(sofar);
            return;
        }
        
        for(int i = 0; i < remain.size(); i++){
            int x = remain[i];
            sofar.push_back(x);
            auto it = remain.erase(remain.begin()+i);
            
            permuteHelper(result, sofar, remain);
            
            sofar.pop_back();
            remain.insert(it, x);
        }
    }
};
