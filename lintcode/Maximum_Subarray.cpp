/**
 * s[i]: max subsum ending at A[i]
 * s[i] = max s[i-1] + A[i]
 *            A[i]
 *            0   <- here only if we could choose no element
 */
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty()) return 0;
        
        int n = nums.size();
        vector<int> s(n, 0);
        int maxSum = nums[0];
        
        s[0] = nums[0];
        for(int i = 1; i < n; i++){
            s[i] = max(s[i-1]+nums[i], nums[i]);
            if(s[i] > maxSum) maxSum = s[i];
        }
        
        return maxSum;
    }
};
