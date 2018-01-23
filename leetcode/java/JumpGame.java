class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        if(nums.length == 0) return false;
        
        int n = nums.length;
        boolean[] s = new boolean[n];
        s[0] = true;
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(s[j] == true && j+nums[j] >= i) {
                    s[i] = true;
                    break;
                }
            }
        }
        
        return s[n-1];
    }
}
