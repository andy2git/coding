class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        bool is_rp = false;
        
        if(n < 0) {
            is_rp = true;
            n *= -1;
        }
        
        double half;
        double result;
        
        half = pow(x, n/2);
        
        if(n%2){
            result = half*half*x;
        }else{
            result = half*half;
        }
        
        if(is_rp) return 1/result;
        else return result;
    }
};
