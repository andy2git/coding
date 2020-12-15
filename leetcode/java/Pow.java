class Solution {
    public double myPow(double x, int n) {
        if(n == 0) return 1;

        double result = pow(x, Math.abs(n));
        if(n < 0) return 1/result;
        else return result;
    }
    
    private double pow(double x, int n) {
        if(n == 0) return 1;
        double t = pow(x, n/2);
        if(n % 2 == 0) return t*t;
        else return t*t*x;
    }
}
