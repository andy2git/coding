public class Solution {
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] A) {
        if(A.length == 0) return 0;
        
        int n = A.length;
        // t[i]: store the max value you can robber
        long[] t = new long[n+1];
        t[0] = 0;
        t[1] = A[0];
        
        for(int i = 2; i<=n; i++){
            t[i] = Math.max(t[i-1], t[i-2]+A[i-1]);
        }
        
        return t[n];
    }
}

public class Solution {
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    public long houseRobber(int[] A) {
        if(A.length == 0) return 0;
        
        int n = A.length;
        // t[i]: store the max value you can robber including A[i-3]
        long[] t = new long[n+3];
        long maxProfit = A[0];
        
        for(int i = 3; i < n+3; i++){
            t[i] = Math.max(t[i-2], t[i-3]) + A[i-3];
            if(t[i] > maxProfit) maxProfit = t[i];
        }
        
        return maxProfit;
    }
}
