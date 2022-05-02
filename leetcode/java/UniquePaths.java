class Solution {
    public int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        
        // this matrix can be optimized to to use O(2*min(m, n))
        int[][] t = new int[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) t[i][j] = 1;
                else {
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        
        return t[m-1][n-1];
    }
}

// use only 2 rows since we only need to go i-1 or j-1
class Solution {
    public int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) throw new IllegalArgumentException("x");
        
        int[][] t = new int[2][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) t[i%2][j] = 1;
                else {
                    t[i%2][j] = t[(i-1)%2][j] + t[i%2][j-1];
                }
            }
        }
        return t[(m-1)%2][n-1];
    }
}
