public class Solution {
    /**    
     * @param nums: an array of integers
     * @return: an integer
     */
    public int findMissing(int[] nums) {
        int n = nums.length;
        
        int sum = 0;
        for(int x : nums){
            sum += x;
        }
        
        return n*(n+1)/2 - sum;
    }
    
    public int findMissing(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != i) return i;
        }
        return nums.length;
    }
}
