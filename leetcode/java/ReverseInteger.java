class Solution {
    public int reverse(int x) {
        // the reason to put this one as a seperate case is Math.abs(Integer.MIN_VALUE) will overflow
        if(x == Integer.MIN_VALUE) return 0;
        boolean flag = false;
        if(x < 0) {
            flag = true;
            x = Math.abs(x);
        }
        
        int result = 0;
        while(x > 0) {
            if(overFlow(result, 10, x%10)) return 0;
            result = result*10 + x % 10;
            x /= 10;
        }
        if(flag) return -1*result;
        else return result;
    }
    
    private boolean overFlow(int result, int base, int dig) {
        if(result > (Integer.MAX_VALUE - dig)/base) return true;
        return false;
    }
}
