/**
 * DP solution
 * -----------|  max   |------------
 * f[i]: max product including A[i]
 * g[i]: min product including A[i]
 * 
 */
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n <= 0) throw runtime_error("wrong input!");
        
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        f[0] = g[0] = A[0];
        int pMax = A[0];
        
        for(int i = 1; i < n; i++){
            int a = f[i-1]*A[i];
            int b = g[i-1]*A[i];
            
            f[i] = max(max(a, b), A[i]);
            g[i] = min(min(a, b), A[i]);
            
            if(f[i] > pMax) pMax = f[i];
        }
        
        return pMax;
    }
};

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
