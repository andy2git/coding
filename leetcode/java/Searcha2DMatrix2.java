/**
 * The matrix of these properties are called Young Tableaus
 */
/* Time complexity is O(m+n) 
 * If we use binary search, the time complexity T(m, n) = 3T(m/4, n/4) + O(1)
 *  
 */
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
