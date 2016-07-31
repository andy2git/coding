public class Solution {
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    public int longestIncreasingSubsequence(int[] nums) {
        if(nums.length == 0) return 0;
        
        int n = nums.length;
        // t[i]: LIS ending with nums[i]
        int[] t = new int[n];
        Arrays.fill(t, 1);
        
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] >= nums[j]){
                    t[i] = Math.max(t[j]+1, t[i]);
                }
            }
            if(t[i] > maxLen){
                maxLen = t[i];
            }
        }
        return maxLen;
    }
}

