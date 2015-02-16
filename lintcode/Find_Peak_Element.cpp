class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if(A.empty()) return -1;
        if(A.size() == 1) return A[0];
        
        int l = 0;
        int h = A.size()-1;
        while(l <= h){
            if(l == h) return l;
            int m = l + (h-l)/2;
            if(cmp(A, m, m-1) && cmp(A, m, m+1)) return m;
            else if(A[m] < A[m+1]) l = m+1;
            else h = m-1;
        }
        
        return -1;
    }
private:
    bool cmp(vector<int> &A, int i, int j){
        if(j < 0 || j >= A.size()) return true;
        else return A[i] > A[j];
    }
};
