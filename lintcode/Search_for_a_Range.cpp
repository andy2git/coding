class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        if(A.empty()) return {-1, -1};
        
        int n = A.size();
        int l = floor(A, target, 0, n-1);
        if(l < 0) return {-1, -1};
        
        int r = ceil(A, target, 0, n-1);
        
        return {l, r};
    }
    
private:
    int floor(vector<int> &A, int x, int s, int e){
        if(s > e) return -1;
        
        int m = s + (e-s)/2;
        if(x < A[m]) return floor(A, x, s, m-1);
        else if(x > A[m]) return floor(A, x, m+1, e);
        else {
            int t = floor(A, x, s, m-1);
            if(t < 0) return m;
            else return t;
        }
    }
    
    int ceil(vector<int> &A, int x, int s, int e){
        if(s > e) return -1;
        
        int m = s + (e-s)/2;
        if(x < A[m]) return ceil(A, x, s, m-1);
        else if(x > A[m]) return ceil(A, x, m+1, e);
        else {
            int t = ceil(A, x, m+1, e);
            if(t < 0) return m;
            else return t;
        }
    }
};
