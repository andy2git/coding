/**
 *  maxSubArray - minSubArray
 *  minSubArray - maxSubArray
 */ 
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        if(nums.size() <= 1) throw runtime_error("wrong input!");
        
        int maxDiff = maxDiffSubArrayHelper(nums);
        reverse(nums.begin(), nums.end());

        maxDiff = max(maxDiff, maxDiffSubArrayHelper(nums));
        
        return maxDiff;
    }
private:
    int maxDiffSubArrayHelper(vector<int> &nums){
        int n = nums.size();
        //tl[i]:max subarray ending at A[i]
        vector<int> tl(n, 0);
        int pre;
        int cur;
        int m;
        m = pre = tl[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            cur = max(pre+nums[i], nums[i]);
            m = max(m, cur);
            tl[i] = m;
            pre = cur;
        }
        
        m = pre = nums[n-1];
        int maxDiff = abs(tl[n-2]-m);
        for(int i = n-2; i > 0; i--){
            cur = min(pre+nums[i], nums[i]);
            m = min(m, cur);
            
            if(abs(tl[i-1]-m) > maxDiff){
                maxDiff = abs(tl[i-1]-m);
            }
            pre = cur;
        }
        
        return maxDiff;
    }
};
