class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] s = new int[n];
        s[0] = 1;
        
        int maxLen = 1;
        for(int i = 1; i < n; i++) {
            s[i] = 1;
            for(int k = 0; k < i; k++) {
                if(nums[k] < nums[i]) {
                    s[i] = Math.max(s[i], s[k]+1);
                }
            }
            maxLen = Math.max(maxLen, s[i]);
        }
        return maxLen;
    }
}
