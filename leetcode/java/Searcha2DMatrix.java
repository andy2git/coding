/*
 * Solution#1 has time complexity of log(m) + log(n)
 * Solution#2 has time complexity of m+n
 */

/* Solution#1 */
// O(lgm + lgn)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0) return false;
        int m = matrix.length;
        int n = matrix[0].length;
        
        int l = 0;
        int h = m*n-1;
        while(l<=h) {
            int k = l + (h-l)/2;
            int x = k/n;
            int y = k%n;
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target) l = k+1;
            else h = k-1;
        }
        return false;
    }
}

/* Solution#2 */
// O(m+n) complexity
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0) return false;
        int m = matrix.length;
        int n = matrix[0].length;
        
        int x = m-1;
        int y = 0;
        while(x >= 0 && y < n) {
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target) x--;
            else y++;
        }
        return false;
    }
}
