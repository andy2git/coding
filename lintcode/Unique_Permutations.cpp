class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if(nums.empty()) return {};
        
        vector<vector<int>> result;
        vector<int> sofar;
        
        // sort to make sure duplicated nums are together
        sort(nums.begin(), nums.end());
        permuteUniqueHelper(result, sofar, nums);
        return result;
    }
    
private:
    void permuteUniqueHelper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain){
        if(remain.empty()){
            result.push_back(sofar);
            return;
        }
        
        for(int i = 0; i < remain.size(); i++){
            if(i > 0 && remain[i] == remain[i-1]) continue;
            
            int x = remain[i];
            sofar.push_back(x);
            auto it = remain.erase(remain.begin()+i);
            
            permuteUniqueHelper(result, sofar, remain);
            
            //restore sofar and remain
            sofar.pop_back();
            remain.insert(it, x);
        }
    }
};
