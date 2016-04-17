class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x < 0) throw runtime_error("wrong input!");
        
        int l= 0;
        int h = x;
        int result = -1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            if(m > 0 && INT_MAX/m < m){
                h = m-1;
                continue;
            }
            int t = m*m;
            
            if(t == x) return m;
            else if(t < x){
                result = m;
                l = m+1;
            }else h = m-1;
        }
        
        return result;
    }
};


