class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        if(n <= 0) return 0;
        
        long long result = 0;
        while(n > 0){
            result += n/5;
            n /= 5;
        }
        return result;
    }
};



