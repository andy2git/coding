class Solution {
    public int minDistance(String w1, String w2) {
        if(w1 == null || w2 == null) throw new IllegalArgumentException("xx");
        int m = w1.length();
        int n = w2.length();
        
        int[][] t = new int[m+1][n+1];
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0) t[i][j] = j;
                else if(j == 0) t[i][j] = i;
                else {
                    if(w1.charAt(i-1) == w2.charAt(j-1)) t[i][j] = t[i-1][j-1];
                    else {
                        t[i][j] = Math.min(Math.min(t[i-1][j], t[i][j-1]), t[i-1][j-1]) +1;
                    }
                }
            }
        }
        return t[m][n];
    }
}
