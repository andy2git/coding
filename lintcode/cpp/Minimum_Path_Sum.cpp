class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0) throw runtime_error("min path does not exist!");
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j > 0) grid[i][j] += grid[i][j-1];
                if(j == 0 && i > 0) grid[i][j] += grid[i-1][j];
                if(i > 0 && j > 0) grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};
