public class Solution {
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    public int maxProfit(int[] prices) {
        if(prices.length <= 1) return 0;
        
        int n = prices.length;
        int[] diff = new int[n-1];
        for(int i = 1; i < n; i++){
            diff[i-1] = prices[i] - prices[i-1];
        }
        
        return maxSum(diff);
    }
    
    private int maxSum(int[] A){
        int n = A.length;
        int[] t = new int[n+1];
        t[0] = 0;
        
        int maxSum = 0;
        for(int i = 1; i <= n; i++){
            t[i] = Math.max(t[i-1]+A[i-1], Math.max(A[i-1], 0));
            if(t[i] > maxSum){
                maxSum = t[i];
            }
        }
        
        return maxSum;
    }
}
