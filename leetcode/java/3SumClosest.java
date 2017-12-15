public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums == null || nums.length < 3) throw new IllegalArgumentException("xxx");
        
        Arrays.sort(nums);
        
        int n = nums.length;
        int minDiff = Integer.MAX_VALUE;
        int candidate = 0;
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int t = nums[i] + nums[j] + nums[k];
                if(t == target) return t;
                
                // keep track of all potential candidates
                if(Math.abs(t-target) < minDiff){
                    minDiff = Math.abs(t-target);
                    candidate = t;
                }
                
                if(t < target) j++;
                else k--;
            }
        }
        return candidate;
    }
}
