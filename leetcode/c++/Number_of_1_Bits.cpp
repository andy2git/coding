/* O(#1s) */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        
        while(n){
            n = n&(n-1);
            cnt++;
        }
        
        return cnt;
    }
};

/* O(32) */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t m = 1;
        while(n){
            if(n&m == 1) cnt++;
            n = n>>1;
        }

        return cnt;
    }
};
