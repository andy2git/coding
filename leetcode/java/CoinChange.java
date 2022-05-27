class Solution {
    public int coinChange(int[] coins, int amount) {
        if(coins == null || coins.length==0) throw new IllegalArgumentException("x");
        
        int max = amount+1;
        int f[] = new int[max];
        Arrays.fill(f, max);
        f[0] = 0;
        for(int i =1; i <=amount; i++) {
            for(int k = 0; k < coins.length; k++){
                if(i -coins[k]>=0) f[i] = Math.min(f[i], f[i-coins[k]]+1);
            }
        }
        if(f[amount] == max) return -1;
        else return f[amount];
    }    
}
