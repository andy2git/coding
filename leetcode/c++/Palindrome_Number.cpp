class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int y = x;
        int a = 1;
        while(y >= 10){
            y /= 10;
            a *= 10;
        }
        
        while(a > 1){
            if(x/a != x%10) return false;
            x %= a;
            x /= 10;
            a /= 100;
        }
        
        return true;
    }
};
