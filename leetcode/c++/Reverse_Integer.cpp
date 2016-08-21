class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool pos = true;
        if(x < 0){
            pos = false;
            x *= -1;
        }
        
        int result = 0;
        
        while(x){
            result = result*10+ x%10;
            x /=10;
        }
        
        if(pos) return result;
        else return result*-1;
    
    }
};
