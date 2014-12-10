/* After padding, we will have at least 3 elems in the input */
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.size() == 1) return 0;
        
        vector<int> A;
        A.push_back(INT_MIN);
        for(int i = 0; i < num.size(); i++) A.push_back(num[i]);
        A.push_back(INT_MIN);
        
        int l = 0;
        int h = A.size()-1;
        int m;
        while(l+1 < h){
            m = l + (h-l)/2;
            if(A[m] > A[m-1] && A[m] > A[m+1]) return m-1;
            if(A[m] < A[m-1]) h = m;
            else l = m;
        }
    }
};

/* Another extension of this problem is the peak in 2-D space */
