class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        if(nums.size() == 0) return {};
        
        vector<vector<int>> result;
        vector<int> sofar;
        subsetHelper(result, sofar, nums, 0);
        
        return result;
    }
private:
    void subsetHelper(vector<vector<int>> &result, vector<int> &sofar, vector<int> &remain, int s){
        if(s == remain.size()){
            result.push_back(sofar);
            return;
        }
        
        int x = remain[s];
        sofar.push_back(x);
        subsetHelper(result, sofar, remain, s+1);
        
        sofar.pop_back();
        subsetHelper(result, sofar, remain, s+1);
    }
};
