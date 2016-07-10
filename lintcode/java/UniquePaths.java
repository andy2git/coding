public class Solution {
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    public int uniquePaths(int m, int n) {
        //check parameters
        if(m <= 0 || n <= 0) throw new IllegalArgumentException("xxx");
        
        int[][] t = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) {
                    t[i][j] = 1;
                } else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        
        return t[m-1][n-1];
    }
}

