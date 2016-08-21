class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tbl(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0) tbl[i][j] = 1;
                else if(j == 0) tbl[i][j] = 1;
                else if(i > 0 && j > 0) tbl[i][j] = tbl[i-1][j] + tbl[i][j-1];
            }
        }
        
        return tbl[m-1][n-1];
    }
};
