class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        if(nums.empty()) return {};
        
        int n = nums.size();
        vector<pair<int, int>> pSum(n+1, {0,0});
        
        for(int i = 0; i < n; i++){
            pSum[i+1].first = pSum[i].first + nums[i];
            pSum[i+1].second = i+1;
        }
        
        sort(pSum.begin(), pSum.end());
        
        int minSum = INT_MAX;
        int s = -1;
        int e = -1;
        for(int i = 0; i < n; i++){
            int diff = abs(pSum[i].first - pSum[i+1].first);
            if(diff <= minSum){
                minSum = diff;
                s = min(pSum[i].second, pSum[i+1].second);
                e = max(pSum[i].second, pSum[i+1].second);
            }
        }
        
        return {s, e-1};
    }
};
