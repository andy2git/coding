/**
 * S[k] max subarray sum ending at k
 * S[k] = max(S[k-1] + A[k], 0)
 * Optimal substructure: optimal max subsum ending at k. S[k-1] must be optimal max sun ending at k-1
 *    - if S[k] < 0, drop it. 
 *    - We also need to keep track of max subarray
 */
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int max_sum = A[0]; // contain at least one element
        
        for(int i = 0; i < n ; i++){
            sum += A[i];

            // max subarray will have at least one elem
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


/** 
 * Divide and conquer solution 
 *
 * |----------------------------------------|
 *           <-------|------>          (1)
 * | <----------->                     (2)
 *                   | <----------->   (3)
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {

        int max_sum;
        max_sum = max_sub_helper(A, 0, n-1);
        
        return max_sum;
    }
private:
    // [sInd, eInd] 
    int max_sub_helper(int A[], int sInd, int eInd){
        if (sInd == eInd) return A[sInd];    // one elem array
        if (sInd > eInd) return INT_MIN;            // empty array
        
        int l_max, r_max, c_max;
        int mInd;
        
        mInd = sInd + (eInd-sInd)/2;
        
        l_max = max_sub_helper(A, sInd, mInd-1);
        r_max = max_sub_helper(A, mInd+1, eInd);
        
        
        int prefix_sum = A[mInd];
        int prefix_max = A[mInd];
        
        for (int i = mInd+1; i <= eInd; i++) {
            prefix_sum += A[i];
            if (prefix_sum > prefix_max) prefix_max = prefix_sum;
        }
        
        int suffix_sum = A[mInd];
        int suffix_max = A[mInd];
        for (int i = mInd-1; i >= 0; i--) {
            suffix_sum += A[i];
            if (suffix_sum > suffix_max) suffix_max = suffix_sum;
        }
        
        int c_max = prefix_sum + suffix_max - A[mInd];
        
        return max(max(l_max, r_max), c_max);
    }
};
