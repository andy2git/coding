public class Solution {
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    public int numTrees(int n) {
        if(n < 0) throw new IllegalArgumentException("xxx");
        
        int[] t = new int[n+1];
        t[0] = 1;
        for(int i = 1; i <=n; i++){
            int sum = 0;
            for(int j = 1; j <=i; j++){
                sum += t[j-1]*t[i-j];
            }
            t[i] = sum;
        }
        
        return t[n];
    }
}
