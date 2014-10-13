class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (x <= 0) return 0;
        
        int t;
        
        int l = 1;
        int h = x;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            
            //overflow case
            if(INT_MAX/m < m) {
                h = m-1;
                continue;
            }
            
            t = m*m;
            if(t == x) return m;
            else if(t < x) l = m+1;
            else h = m-1;
        }
        
        return (l+h)/2;
    }
};

class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (x <= 0) return 0;
        
        int result;
        int error, max_error = INT_MAX;
        
        int l = 1;
        int h = x;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            //overflow case
            if(INT_MAX/m < m) {
                h = m-1;
                continue;
            }
            error = x - m*m;
            if(error == 0) return m;
            else if(error > 0){
                l = m+1;
                if(error < max_error){
                    max_error = error;
                    result = m;
                }
            } 
            else h = m-1;
        }
        
        return result;
    }
};
