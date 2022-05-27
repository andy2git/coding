class Solution {
    public int findNumberOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int n = nums.length;

        //s[i]: LIS ending with nums[i].
        // and the optimal LIS has to be one of s[i]
        int[] s = new int[n];
        s[0] = 1;
        int[] c = new int[n];
        c[0] = 1;
        
        int maxLen = 1;
        int count = 1;
        for(int i = 1; i < n; i++) {
            // you can always chose yourself as the LIS
            s[i] = 1;
            for(int k = 0; k < i; k++) {
                if(nums[k] < nums[i]) {
                    s[i] = Math.max(s[i], s[k]+1);
                }
            }
            
            for(int k = 0; k < i; k++) {
                if(s[i] == s[k]+1 && nums[k] < nums[i]) c[i] +=c[k];
            }
            if(c[i] == 0) c[i] = 1;
            
            maxLen = Math.max(maxLen, s[i]);
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == maxLen) sum+=c[i];
        }
        
        return sum;
    }
}
