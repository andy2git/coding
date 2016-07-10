public class Solution {
    /**
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    public int minSubArray(List<Integer> nums) {
        if(nums == null || nums.isEmpty()) throw new IllegalArgumentException("xxx");

        int pre = 0;
        int cur = 0;
        int minSum = nums.get(0);
        for(int x : nums) {
            cur = Math.min(pre+x, x);
            if(cur < minSum) minSum = cur;
            pre = cur;
        }
        return minSum;
    }
}
