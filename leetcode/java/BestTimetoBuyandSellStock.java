class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2) return 0;
        int[] d = new int[prices.length-1];
        for(int i = 1; i < prices.length; i++){
            d[i-1] = prices[i] - prices[i-1];
        }
        return ph(d);
    }
    
    private int ph(int[] A) {
        if(A == null || A.length == 0) throw new IllegalArgumentException("x");
        int[] t = new int[A.length];
        int result = 0;
        for(int i = 0; i < t.length; i++) {
            if(i == 0) t[0] = Math.max(A[0], 0);
            else {
                t[i] = Math.max(t[i-1]+A[i], Math.max(A[i], 0));
            }
            result = Math.max(result, t[i]);
        }
        return result;
    }
}
