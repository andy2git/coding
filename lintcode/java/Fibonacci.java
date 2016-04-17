class Solution {
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    public int fibonacci(int n) {
        if(n <= 0) throw new IllegalArgumentException("n cannot be < 0");
        if(n <= 2) return n-1;
        
        int f = 0;
        int s = 1;
        int t = 0;
        
        while(n > 2){
            t = f + s;
            f = s;
            s = t;
            n--;
        }
        return t;
    }
}

