class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum = 0;
        int n = gas.length;
        int pSum = 0;
        int cand = -1;
        
        for(int i = 0; i < n; i++) {
            int t = gas[i] - cost[i];
            sum += t;
            pSum += t;
            
            if(pSum < 0) {
                cand = -1;
                pSum = 0;
            }else{
                if(cand == -1) cand = i;
            }
        }
        if (sum < 0) return -1;
        return cand;
    }
}
