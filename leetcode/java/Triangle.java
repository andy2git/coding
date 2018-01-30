class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.isEmpty()) return 0;
        int m = triangle.size();
        int n = triangle.get(m-1).size();
        
        int[][] t = new int[m][n];
        int k = n;
        for(int i = m-1; i >= 0; i--) {
            for(int j = 0; j < k; j++) {
                if(i == m-1) t[i][j] = triangle.get(i).get(j);
                else t[i][j] = Math.min(t[i+1][j], t[i+1][j+1]) + triangle.get(i).get(j);
            }
            k--;
        }
        return t[0][0];
    }
}
