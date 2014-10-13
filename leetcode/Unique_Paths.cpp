class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tbl(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                tbl[i][j] = tbl[i-1][j] + tbl[i][j-1];
            }
        }
        
        return tbl[m-1][n-1];
    }
};
