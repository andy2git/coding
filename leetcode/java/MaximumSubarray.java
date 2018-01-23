class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("xx");
        
        // s[i]: max subarray ending/including nums[i]
        int[] s = new int[nums.length];
        int sum = nums[0];
        s[0] = nums[0];
        for(int i = 1; i < nums.length; i++) {
            s[i] = Math.max(nums[i], s[i-1]+nums[i]);
            sum = Math.max(sum, s[i]);
        }
        return sum;
    }
}
