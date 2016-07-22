public class Solution {
    /**
     * @param nums: an array of integers
     * @return: an integer
     */
    public int maxProduct(int[] nums) {
        if(nums.length == 0) throw new IllegalArgumentException("xx");
        if(nums.length == 1) return nums[0];
        
        int n = nums.length;
        int[] pos = new int[n+1];
        int[] neg = new int[n+1];
        pos[0] = neg[0] = 1;
        
        int maxProd = Integer.MIN_VALUE;
        for(int i = 1; i <= n; i++) {
            int a = pos[i-1]*nums[i-1];
            int b = neg[i-1]*nums[i-1];
            
            pos[i] = Math.max(Math.max(a, b), nums[i-1]);
            neg[i] = Math.min(Math.min(a, b), nums[i-1]);
            if(pos[i] > maxProd) maxProd = pos[i];
        }
        
        return maxProd;
    }
}
