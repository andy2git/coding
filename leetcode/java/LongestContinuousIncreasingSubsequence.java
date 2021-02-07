class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int maxLen = 0;
        int cnt = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > nums[i-1]) cnt++;
            else {
                maxLen = Math.max(maxLen, cnt);
                cnt = 1;
            }
        }
        return Math.max(maxLen, cnt);
    }
}

// same approach like above
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        
        int maxLen = 1;
        int len = 1;
        for(int i = 0; i < nums.length-1; i++) {
            if(nums[i] < nums[i+1]) len++;
            else {
                maxLen = Math.max(maxLen, len);
                len = 1;
            }
        }
        return Math.max(len, maxLen);
    }
}
