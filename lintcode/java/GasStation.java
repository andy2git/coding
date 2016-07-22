public class Solution {
    /**
     * @param gas: an array of integers
     * @param cost: an array of integers
     * @return: an integer
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if(gas.length == 0 || cost.length == 0 || gas.length != cost.length) throw new IllegalArgumentException("xx");
        
        int sum = 0;
        int remain = 0;
        int ind = 0;
        
        int n = gas.length;
        for(int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
            remain += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                ind = i+1;
            }
        }
        
        if(ind < n && remain >= 0) return ind;
        return -1;
    }
}
