class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("x");
        if(nums.length == 0) return false;
        
        int n = nums.length;
        boolean[] s = new boolean[n];
        s[0] = true;
        for(int i = 1; i < n; i++) {
            // if any j can reach me, I will be good
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


// Solution#2
class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null || nums.length <=1) return true;
        int n = nums.length;
        boolean[] f = new boolean[n];
        
        for(int i = 0; i < n-1; i++) {
            f[0] = true;
            if(!f[i]) return false;
            // this approach will write f[j] multiple times
            for(int j = i; j <= Math.min(i+nums[i], n-1); j++) {
                f[j] = true;
            }
        }
        return f[n-1];
    }
}
