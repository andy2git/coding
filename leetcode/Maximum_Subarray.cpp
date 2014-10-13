class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int max_sum = A[0]; // contain at least one element
        
        for(int i = 0; i < n ; i++){
            sum += A[i];
            // make sure every elememt is compared
            if(sum > max_sum){
                max_sum = sum;
            }
            
            if(sum < 0){
                sum = 0;
            }
        }
        return max_sum;
    }
};


/* Divide and conquer solution */

class Solution {
public:
    int maxSubArray(int A[], int n) {

        int max_sum;
        max_sum = max_sub_helper(A, 0, n);
        
        return max_sum;
    }
private:
    
    int max_sub_helper(int A[], int sInd, int eInd){
        if (sInd+1 == eInd) return A[sInd];    // one elem array
        if (sInd >= eInd) return INT_MIN;            // empty array
        
        int l_max, r_max, c_max;
        int mInd;
        
        mInd = sInd + (eInd-sInd)/2;
        
        l_max = max_sub_helper(A, sInd, mInd);
        r_max = max_sub_helper(A, mInd+1, eInd);
        
        
        c_max = A[mInd];
        
        int prefix_sum = 0;
        int prefix_max = INT_MIN;
        
        for (int i = mInd+1; i < eInd; i++) {
            prefix_sum += A[i];
            if (prefix_sum > prefix_max) prefix_max = prefix_sum;
        }
        
        if (prefix_max > 0) {
            c_max += prefix_max;
        }
        
        int suffix_sum = 0;
        int suffix_max = INT_MIN;
        for (int i = mInd-1; i >= 0; i--) {
            suffix_sum += A[i];
            if (suffix_sum > suffix_max) suffix_max = suffix_sum;
        }
        
        if (suffix_max > 0) {
            c_max += suffix_max;
        }
        
        return max(max(l_max, r_max), c_max);
    }
};
