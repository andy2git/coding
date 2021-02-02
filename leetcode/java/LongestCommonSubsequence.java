class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] A = text1.toCharArray();
        char[] B = text2.toCharArray();
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
