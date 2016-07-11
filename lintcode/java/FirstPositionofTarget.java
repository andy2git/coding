class Solution {
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    public int binarySearch(int[] nums, int target) {
        if(nums.length == 0) return -1;
        int l = 0;
        int h = nums.length-1;
        
        int ret = -1;
        while(l <= h){
            int m = l + (h-l)/2;
            if(target > nums[m]){
                l = m+1;
            }else if(target < nums[m]){
                h = m-1;
            }else {
                ret = m;
                h = m-1;
            }
        }
        
        return ret;
    }
}
