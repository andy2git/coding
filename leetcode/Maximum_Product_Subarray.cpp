/**
 *
 */

/*
 * ------pMin-> 
 * ------pMax->
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 1) return A[0];
        
        int pMin = A[0];
        int pMax = A[0];
        int cMin, cMax;
        int maxProduct = pMax;
        
        for(int i = 1; i < n; i++){
            cMin = min(min(pMax*A[i], pMin*A[i]), A[i]);
            cMax = max(max(pMax*A[i], pMin*A[i]), A[i]);
            if(cMax > maxProduct) maxProduct = cMax;
            pMin = cMin;
            pMax = cMax;
        }
        
        return maxProduct;
    }
};
