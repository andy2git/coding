class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        if(A.empty()) return 1;
        int n = A.size();
        
        for(int i = 0; i < n; i++){
            if(A[i] <= 0) A[i] = n+1;
        }
        
        for(int i = 0; i < n; i++){
            int k = abs(A[i]);
            if(k <= n && A[k-1] > 0) A[k-1] *=-1;
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] > 0) return i+1;
        }
        return n+1;
    }
};
