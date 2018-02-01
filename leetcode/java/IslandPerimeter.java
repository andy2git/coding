class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid == null || grid.length == 0) return 0;
        int result = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1) result += perimeter(grid, i, j);
            }
        }
        return result;
    }
    
    private int perimeter(int[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;
        int p = 0;
        
        if(j == 0 || grid[i][j-1] == 0) p++;
        if(j == n-1 || grid[i][j+1] == 0) p++;
        if(i == 0 || grid[i-1][j] == 0) p++;
        if(i == m-1 || grid[i+1][j] == 0) p++;
        return p;
    }
}
