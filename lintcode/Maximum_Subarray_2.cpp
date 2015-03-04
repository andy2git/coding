/** 
 * Similar to purchase stock problem with two purchases,
 * t[i]: max subarray ending at A[i] - instead of using an array, we can use two variables: pre, cur
 * tl[i]: store the max sum so far.
 */
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        if(nums.size() <= 1) throw runtime_error("wrong input!");
        
        int n = nums.size();
        vector<int> tl(n, 0);
        int pre = nums[0];
        int cur;
        int m = tl[0] = pre;
        for(int i = 1; i < n; i++){
            cur = max(nums[i], pre+nums[i]);
            m = max(m, cur);
            tl[i] = m;
            pre = cur;
        }
        
        int maxSum = tl[n-2] + nums[n-1];
        m = pre = nums[n-1];
        for(int i = n-2; i > 0; i--){
            cur = max(nums[i], nums[i]+pre);
            m = max(m, cur);
            if(m+tl[i-1] > maxSum){
                maxSum = m+tl[i-1];
            }
            pre = cur;
        }
        
        return maxSum;
    }
};
