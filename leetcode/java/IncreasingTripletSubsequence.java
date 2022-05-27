class Solution {
    public boolean increasingTriplet(int[] nums) {
        if(nums == null || nums.length <= 0) throw new IllegalArgumentException("x");
        
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] < first) first = nums[i];
            if(nums[i] > first) second = Math.min(second, nums[i]);
            if(nums[i] > second) return true;
        }
        
        return false;
    }
}
