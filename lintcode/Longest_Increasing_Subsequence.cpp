class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.size() <= 1) return nums.size();
        
        int n = nums.size();
        vector<int> L(n, 1);
        int maxLen = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int t;
                if(nums[i] >= nums[j]) t = L[j] + 1;
                else t = 1;
                
                if(t > L[i]) L[i] = t;
            }
            if(L[i] > maxLen) maxLen = L[i];
        }
        
        return maxLen;
    }
};



