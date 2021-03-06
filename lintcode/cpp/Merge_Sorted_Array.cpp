class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int i = 0;
        int j = 0;
        
        vector<int> result;
        while(i < m && j < n){
            if(A[i] <= B[j]) result.push_back(A[i++]);
            else result.push_back(B[j++]);
        }
        
        while(i < m) result.push_back(A[i++]);
        while(j < n) result.push_back(B[j++]);
        
        return result;
    }
};
