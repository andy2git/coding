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

// Identical solution comparing to above one. 
//                     f(6)
                    1         2     5
//               f(5)       f(4)   f(1)
            1     2   5      -> this f(4) will not be computed, so total time complexity is: O(amount * #coins)
//        f(4)  f(3) f(0)
// you will see overlapping subproblems
// 
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(coins == null || coins.length == 0) return 0;
        
        int max = amount+1;
        int[] f = new int[amount+1];
        f[0] = 0;
        for(int i = 1; i <= amount; i++) {
            f[i] = max;
        }
        
        for(int i = 1; i <= amount; i++) {
            for(int x : coins) {
                // if f[i-x] is max, Math.min will return max
                if(i - x >= 0) f[i] = Math.min(f[i], f[i-x]+1);
            }
        }
        if(f[amount] == max) return -1;
        else return f[amount];
    }
}
