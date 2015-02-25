class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int cnt = 0;

        // used to handle the negative numbers
        unsigned int m = a;
        unsigned int n = b;
        while(m > 0 || n > 0){
            int x = m%2;
            int y = n%2;
            if(x != y) cnt++;
            m /=2;
            n /=2;
        }
        
        return cnt;
    }
};
