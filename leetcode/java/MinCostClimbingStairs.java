class Solution {
    /**
     *  ---------------------------------
     * the min cost has to come from n-1 or n-2
     * so we define s[i] as the cost of moving THROUGH a[i]
     **/
    public int minCostClimbingStairs(int[] cost) {
        if(cost == null || cost.length == 0) throw new IllegalArgumentException("xx");
        if(cost.length == 1) return 0;
        int n = cost.length;
        int[] s = new int[n];
        s[0] = cost[0];
        s[1] = cost[1];
        
        for(int i = 2; i < n; i++) {
            s[i] = Math.min(s[i-1], s[i-2]) + cost[i];
        }
        
        return Math.min(s[n-1], s[n-2]);
    }
}
