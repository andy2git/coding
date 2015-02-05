class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> tbl(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    tbl[i][j] = 0;
                    continue;
                }
                
                // no obstacle 
                if(i == 0 && j == 0) tbl[i][j] = 1;
                else if(i == 0 && j > 0) tbl[i][j] = tbl[i][j-1];
                else if(j == 0 && i > 0) tbl[i][j] = tbl[i-1][j];
                else tbl[i][j] = tbl[i-1][j] + tbl[i][j-1];
            }
        }
        
        return tbl[m-1][n-1];
    }
};
