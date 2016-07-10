public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    public int maxSubArray(int[] nums) {
        if(nums.length == 0) throw new IllegalArgumentException("xxx");
        
        int n = nums.length;
        // t[i] : max subarray sum ending at A[i]
        int[] t = new int[n];
        
        int maxSum = t[0] = nums[0];
        for(int i = 1; i < n; i++){
            t[i] = Math.max(t[i-1]+nums[i], nums[i]);
            if(t[i] > maxSum) maxSum = t[i];
        }
        
        return maxSum;
    }
}
