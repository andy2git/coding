class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[]{-1, -1};
        int f = floor(nums, 0, nums.length-1, target);
        if (f == -1) return new int[]{-1, -1};
        else {
            int c = ceiling(nums, target);
            return new int[]{f, c};
        }
        
    }
    
    private int floor(int[] nums, int l, int h, int t) {
        if(l > h) return -1;
        int m = l + (h-l)/2;
        if(t < nums[m]) return floor(nums, l, m-1, t);
        else if (t > nums[m]) return floor(nums, m+1, h, t);
        else {
            int f = floor(nums, l, m-1, t);
            if(f == -1) return m;
            else return f;
        }
    }
    
    private int ceiling(int[] nums, int t) {
        int l = 0;
        int h = nums.length-1;
        int m;
        
        int ub = -1;
        while(l <= h) {
            m = l + (h-l)/2;
            if(nums[m] < t) l = m+1;
            else if(nums[m] > t) h = m-1;
            else {   
                ub = m;
                l = m+1;
            }
        }
        return ub;
    }
}
