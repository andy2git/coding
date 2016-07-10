public class Solution {
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    public int minimumTotal(int[][] triangle) {
        // parameter check or base case
        if(triangle.length == 0) return 0;
        
        int m = triangle.length;
        int n = triangle[m-1].length;
        
        int[][] t = new int[m][n];
        
        // init last row
        for(int j = m-1; j >= 0; j--){
            t[m-1][j] = triangle[m-1][j];
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                t[i][j] = Math.min(t[i+1][j], t[i+1][j+1]) + triangle[i][j];
            }
        }
        return t[0][0];
    }
}

