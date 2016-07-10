public class Solution {
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0) return false;
        int m = matrix.length;
        int n = matrix[0].length;
        
        int i = 0;
        int j = n-1;
        while(i < m && j >= 0){
            if(target < matrix[i][j]) j--;
            else if(target > matrix[i][j]) i++;
            else return true;
        }
        
        return false;
    }
}

