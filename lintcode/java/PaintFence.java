public class Solution {
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */

    /*
     * two cases you need to exclude:
     *  --x
     *  x--
     */
    public int numWays(int n, int k) {
        if(n <= 0 || k <= 0) throw new IllegalArgumentException("xxx");
        if(n == 1) return k;
        
        int[] t = new int[n];
        t[0] = k;
        t[1] = k*k;
        
        for(int i = 2; i < n; i++){
            t[i] = (k-1)*(t[i-1] + t[i-2]);
        }
        return t[n-1];
    }
}
