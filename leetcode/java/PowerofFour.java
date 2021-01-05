class Solution {
    public boolean isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        
        // check it only contains 1
        if((num&(num-1)) != 0) return false;
        
        // 4^n = 2^2n, so we only need to check if we have even number of 1s for num-1
        // check we only have even number of 0s
        num = num-1;
        int cnt = 0;
        while(num > 0) {
            cnt++;
            num &= num-1;
        }
        return cnt%2 == 0;
    }
}
