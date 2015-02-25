class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if(nums.size() == 0) throw runtime_error("no input!");
        
        int n = nums.size();
        vector<int> s(n, 0);
        s[0] = nums[0];
        int minSum = s[0];
        
        for(int i = 1; i < nums.size(); i++){
            s[i] = min(s[i-1]+nums[i], nums[i]);
            if(s[i] < minSum) minSum = s[i];
        }
        
        return minSum;
    }
};
