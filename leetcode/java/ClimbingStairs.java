class Solution {
    public int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n <= 2) return n;
        
        int[] d = new int[n];
        d[0] = 1;
        d[1] = 2;
        for(int i = 2; i < n; i++) {
            d[i] = d[i-1] + d[i-2];
        }
        return d[n-1];
    }
}


// fibnaci way
class Solution {
    public int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n <= 2) return n;
        
        int f = 1;
        int s = 2;
        int t = 0;
        for(int i = 2; i < n; i++) {
            t = f+s;
            f = s;
            s = t;
        }
        return t; 
    }
}
