class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 0) return 0;
        
        vector<int> L(n, 0);
        
        int max = A[0];
        L[0] = A[0];
        
        for(int i = 1; i < n; i++){
            L[i] = max;
            if(A[i] > max) max = A[i];
        }
        
        max = A[n-1];
        
        int t;
        int sum = 0;
        // water cannot be trapped in the first and the last
        for(int i = n-2; i > 0; i--){
            t = min(max, L[i]) - A[i];
            if(t > 0) sum += t;
            if(A[i] > max) max = A[i];
        }
        
        return sum;
    }
};

class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 0) return 0;
        
        vector<int> L(n, 0);
        vector<int> R(n, 0);
        
        int max = A[0];
        L[0] = A[0];
        
        for(int i = 1; i < n; i++){
            L[i] = max;
            if(A[i] > max) max = A[i];
        }
        
        max = A[n-1];
        R[n-1] = A[n-1];
        
        for(int i = n-2; i >= 0; i--){
            R[i] = max;
            if(A[i] > max) max = A[i];
        }
        
        int sum = 0;
        int t;
        for(int i = 0; i < n; i++){
            t = min(L[i], R[i]) - A[i];
            if(t > 0) sum += t;
        }
        return sum;
    }
};
