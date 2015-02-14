class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n < 0) throw runtime_error("wrong input!");
        if(n <= 1) return 1;
        
        int first = 1;
        int second = 1;

        while(n > 1){
            int third = first + second;
            first = second;
            second = third;
            n--;
        }
        
        return second;
    }
};



