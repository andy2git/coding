/* After padding, we will have at least 3 elems in the input */
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.size() == 1) return 0;
        
        vector<int> A(num.size()+2);
        A[0] = INT_MIN;
        copy(num.begin(), num.end(), A.begin()+1);
        A[A.size()-1] = INT_MIN;
        
        int l = 0;
        int h = A.size()-1;
        int m;
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] > A[m+1] && A[m] > A[m-1]) return m-1;
            if(A[m] < A[m+1]) l = m+1;
            else h = m-1;
        }
        return -1;
    }
};

/* Another extension of this problem is the peak in 2-D space */
