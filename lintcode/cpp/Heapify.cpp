class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        if(A.size() <= 1) return;
        
        int n = A.size();
        for(int i = (n-2)/2; i >= 0; i--){
            sink(A, i);
        }
    }
    
private:
    void sink(vector<int> &A, int k){
        int n = A.size();
        
        while(k < n){
            int i = 2*k+1;
            if(i >= n) break;
            
            if(i < n-1 && A[i] > A[i+1]) i++;
            if(A[k] < A[i]) break;
            
            swap(A[k], A[i]);
            k = i;
        }
    }
};


