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

// Same solution as above
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0) return 0;
        int[] df = priceDiff(prices);
        return maxSubarray(df);
    }
    
    // s[i]: max subarray sum including A[i-1]
    private int maxSubarray(int[] A) {
        int n = A.length;
        int[] s = new int[n+1];
        int max = s[0];
        for(int i = 1; i <=n; i++) {
            s[i] = Math.max(0, Math.max(s[i-1] + A[i-1], A[i-1]));
            max = Math.max(max, s[i]);
        }
        return max;
    }
    
    private int[] priceDiff(int[] p) {
        int n = p.length;
        int[] df = new int[n-1];
        for (int i =0; i < n-1; i++) {
            df[i] = p[i+1] - p[i];
        }
        return df;
    }
    
}
