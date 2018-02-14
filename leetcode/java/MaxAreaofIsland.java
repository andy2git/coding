class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if(grid == null || grid.length == 0) return 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] t = new boolean[m][n];
        
        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !t[i][j]) {
                    t[i][j] = true;
                    int area = mah(grid, t, i , j);
                    maxArea = Math.max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
    
    private int mah(int[][] A, boolean[][] t, int i, int j) {
        // there is no base case, as the node without legit candidates will just return 1
        int m = A.length;
        int n = A[0].length;
        int[][] cands = new int[][]{{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
        int cnt = 1;
        for(int[] cand : cands) {
            int x = cand[0];
            int y = cand[1];
            if(x >= 0 && x < m && y >= 0 && y < n) {
                if(A[x][y] == 1 && !t[x][y]) {
                    t[x][y] = true;
                    cnt += mah(A, t, x, y);
                }
            }
        }
        return cnt;
    }
}
