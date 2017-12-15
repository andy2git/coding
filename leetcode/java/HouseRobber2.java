public class Solution {
    //NOTE:
    // [1,n-1] and [0,n-2]
    // robHelper can take the whole array 
    // or array with start, end index as well depending on your prefs
    public int rob(int[] nums) {
        if(nums == null) throw new IllegalArgumentException("xxx");
        int n = nums.length;
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        return Math.max(robHelper(Arrays.copyOfRange(nums, 0, n-1)),
                        robHelper(Arrays.copyOfRange(nums, 1, n)));
    }
    
    private int robHelper(int[] nums){
        if(nums == null) throw new IllegalArgumentException("xxx");
        if(nums.length == 0) return 0;

        int n = nums.length;
        int[] t = new int[n+1];

        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2; i <= n; i++){
            t[i] = Math.max(t[i-2]+nums[i-1], t[i-1]);
        }

        return t[n];
    }
}
