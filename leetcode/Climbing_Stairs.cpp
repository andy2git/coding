class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        
        int first = 1;
        int second = 1;
        int third;
        
        while(n > 1){
            third = first + second;
            first = second;
            second = third;
            n--;
        }
        
        return second;
    }
};
