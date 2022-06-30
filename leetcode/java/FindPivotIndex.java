class Solution {
    public int pivotIndex(int[] nums) {
        if(nums == null || nums.length <= 1) return -1;
        
        int n = nums.length;
        int[] ps = new int[n+1];
        ps[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            ps[i] = ps[i+1] + nums[i];
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum == ps[i+1]) return i;
            sum += nums[i];
        }
        return -1;
    }
}


// much easier to write code
class Solution {
    public int pivotIndex(int[] nums) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("x");
        
        int sum = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        int ls = 0;
        for(int i = 0; i<n; i++) {
            if(sum-ls-nums[i] == ls) return i;
            ls += nums[i];
        }
        return -1;
    }
}
