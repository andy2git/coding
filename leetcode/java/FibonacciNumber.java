class Solution {
    public int fib(int n) {
        int f = 0;
        int s = 1;
        int t = n;
        
        while (n >= 2) {
            t = f + s;
            f = s;
            s = t;
            n--;
        }
        
        return t;
    }
}
