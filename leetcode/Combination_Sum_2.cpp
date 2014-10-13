class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        
        combine_helper(result, num, 0, target, vector<int>());
        
        return result;
    }
private:
    void combine_helper(vector<vector<int>> &result, vector<int> &num, int s, int target, vector<int> sofar){
        if(target == 0){
            result.push_back(sofar);
            return;
        }
        
        if(s >= num.size()){
            return;
        }
        
        int i = s;
        while(i < (int)num.size()-1 && num[i] == num[i+1]) i++;
        
        // not choose any element
        combine_helper(result, num, i+1, target, sofar);
        
        for(int k = s; k <= i; k++){
            sofar.push_back(num[s]);
            target -= num[s];
            if(target < 0) return;
            
            combine_helper(result, num, i+1, target, sofar);
        }
    }
};
