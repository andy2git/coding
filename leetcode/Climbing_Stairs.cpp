class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int first = 1;
        int second = 2;
        int third;
        while(n > 2){
            third = first+second;
            first = second;
            second = third;
            n--;
        }
        return second;
    }
};
