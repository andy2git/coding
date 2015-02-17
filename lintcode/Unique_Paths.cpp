class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int>> t(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        
        return t[m-1][n-1];
    }
};
