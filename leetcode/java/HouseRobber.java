/**
 * s[i]: max $ robbed till nums[i] position
 * if we define s[i] as the max $ robbed with nums[i], then we also need to keep an variable
 * maintaining global max.
 * 
 * See *Min Cost Climbing Stairs* for comparisiont
 **/
public class Solution {
    public int rob(int[] nums) {
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
