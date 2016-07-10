public class Solution {
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    public int longestCommonSubstring(String A, String B) {
        
        int m = A.length();
        int n = B.length();
        int[][] t = new int[m+1][n+1];
        
        int maxLen = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(A.charAt(i-1) == B.charAt(j-1)){
                    t[i][j] = t[i-1][j-1] + 1;
                    if(t[i][j] > maxLen) maxLen = t[i][j];
                } else {
                    t[i][j] = 0;
                }
            }
        }
        
        return maxLen;
    }
}
