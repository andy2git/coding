class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int sum = 0;
        
        for(int i = 0; i <= n; i++){
            sum += numOfK(i, k);
        }
        
        return sum;
    }
private:
    int numOfK(int x, int k){
        int cnt = 0;
        if(x == k) return 1;
        
        while(x > 0){
            int t = x%10;
            if(t == k) cnt++;
            x /= 10;
        }
        
        return cnt;
    }
};
