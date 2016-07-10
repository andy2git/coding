public class Solution {
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    public int longestCommonSubsequence(String A, String B) {
        // parameter check
        if(A == null || A.length() == 0) return 0;
        if(B == null || B.length() == 0) return 0;
        
        int m = A.length();
        int n = B.length();
        int[][] t = new int[m+1][n+1];
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++) {
                if(A.charAt(i-1) == B.charAt(j-1)) t[i][j] = t[i-1][j-1] +1;
                else t[i][j] = Math.max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[m][n];
    }
}

