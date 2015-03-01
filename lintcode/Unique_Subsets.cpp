class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        if(nums.empty()) return {};
        
        vector<vector<int>> result;
        vector<int> sofar;
        
        sort(nums.begin(), nums.end());
        subSetHelper(result, sofar, nums, 0);
        return result;
    }
private:
    void subSetHelper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain, int s){
        if(s == remain.size()){
            result.push_back(sofar);
            return;
        }
        
        
        int i = s+1;
        while(i < remain.size() && remain[i] == remain[i-1]) i++;
        subSetHelper(result, sofar, remain, i);
        
        sofar.push_back(remain[s]);
        subSetHelper(result, sofar, remain, s+1);
            
        sofar.pop_back();
    }
};
