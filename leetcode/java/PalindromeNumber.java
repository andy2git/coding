class Solution {
    public boolean isPalindrome(int x) {
        //if(x == Integer.MIN_VALUE) return false;
        if(x < 0) return false; // depends what we want
        
        //find max base
        int maxBase = findMaxBase(x);
        while(x > 0) {
            if(x/maxBase != x%10) return false;
            x %=maxBase;
            x /=10;
            maxBase /= 100;
        }
        return true;
    }
    
    private int findMaxBase(int x) {
        int base = 1;
        while(x >= 10){
            base *=10;
            x /= 10;
        }
        return base;
    }
}
