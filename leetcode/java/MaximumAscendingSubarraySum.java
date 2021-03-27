class Solution {
    public int maxAscendingSum(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > nums[i-1]) sum += nums[i];
            else {
                maxSum = Math.max(maxSum, sum);
                sum = nums[i];
            }
        }
        maxSum = Math.max(maxSum, sum);
        
        return maxSum;
    }
}
