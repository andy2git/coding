/* 
 * 1. remove all the negative numbers and zeros to get ready for mark up
 * 2. if a certain number exists, then mark number on that position into negative
 * 3. if a number is still positive, which means that number is missing.
 */
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n <= 0) return 1;
        
        // the upper bound for the first missing positive integer [1, n+2)
        for(int i = 0; i < n; i++){
            if(A[i] <= 0) A[i] = n+2; // also mark out zeros
        }
    
        // mark the cell where the positive between 1 and n showing up
        // indicate if an integer exists
        for(int i = 0; i < n; i++){
            int a = abs(A[i]);
            if(a <= n){ //mark the index for a into neg. number to indicate that it exists
                A[a-1] = (A[a-1] > 0)? -1*A[a-1]: A[a-1];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] > 0){
                return i+1;
            }
        }
        
        return n+1;
    }
};
