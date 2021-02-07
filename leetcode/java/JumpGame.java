// Recursive solution - should be the first solution coming up
class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null || nums.length == 0) return true;
        return cjh(nums, 0);
    }
    
    private boolean cjh(int[] A, int pos) {
        if(pos >= A.length) return true;
        if(pos + A[pos] >= A.length-1) return true;
        
        for(int i = pos+1; i <= pos+A[pos]; i++) {
            if(cjh(A, i)) return true;
        }
        return false;
    }
}

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

//Solution#3 
// Greedy approach
class Solution {
    public boolean canJump(int[] nums) {
        if(nums == null || nums.length == 0) return true;
        
        int n = nums.length;
        int lp = n-1;
        for(int i = n-2; i >= 0; i--) {
            if(i+nums[i] >=lp) lp = i;
        }
        
        return lp == 0;
    }
}
