class Solution {
    public int findMin(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("xx");
        int l = 0;
        int h = nums.length-1;
        while(l <= h) {
            if(l == h) return nums[l];
            int m = l + (h-l)/2;
            if(nums[m] < nums[h]) h = m;
            else l = m+1;
        }
        throw new IllegalArgumentException("x");
    }
}
