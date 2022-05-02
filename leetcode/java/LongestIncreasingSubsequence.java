class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int n = nums.length;

        //s[i]: LIS ending with nums[i].
        // and the optimal LIS has to be one of s[i]
        int[] s = new int[n];
        s[0] = 1;
        
        int maxLen = 1;
        for(int i = 1; i < n; i++) {
            // you can always chose yourself as the LIS
            s[i] = 1;
            for(int k = 0; k < i; k++) {
                if(nums[k] < nums[i]) {
                    s[i] = Math.max(s[i], s[k]+1);
                }
            }
            maxLen = Math.max(maxLen, s[i]);
        }
        return maxLen;
    }
}

// Solution #2
// covert the problem into lcs problem
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int[] clone = nums.clone();
        int[] sorted = Arrays.stream(clone).sorted().distinct().toArray();
        
        return lcs(nums, sorted);
    }
    
     public int lcs(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        int[][] t = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) t[i][j] = 0;
                else {
                    if (A[i-1] == B[j-1]) t[i][j] = t[i-1][j-1] + 1;
                    else t[i][j] = Math.max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
}
