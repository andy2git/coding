public class Solution {
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    public double myPow(double x, int n) {
        if(x == 0) return 0;
        
        if(n < 0) {
            return 1/myPowerHelper(x, -1*n);
        } else {
            return myPowerHelper(x, n);
        }
    }
    
    private double myPowerHelper(double x, int n) {
        if(n < 0) throw new IllegalArgumentException("xxx");
        if(n == 0) return 1;
        
        double half = myPow(x, n/2);
        if(n % 2 == 0){
            return half * half;
        } else {
            return half * half *x;
        }
    }
}
