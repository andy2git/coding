class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        if(A.empty()) return 0;
        
        int ind = searchHelper(A, 0, A.size()-1, target);
        if(ind < 0) return A.size();
        else return ind;
    }
private:
    int searchHelper(vector<int> &A, int l, int h, int target){
        if (l > h) return -1;
        int m = l + (h-l)/2;
        
        if(A[m] == target) return m;
        else if(target > A[m]) return searchHelper(A, m+1, h, target);
        else {
            int t = searchHelper(A, l, m-1, target);
            if(t < 0) return m;
            else return t;
        }
    }
};

/* Iterative approach */
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        if(A.empty()) return 0;
       
        int l = 0;
        int h = A.size()-1;
        
        while(l <= h){
            if(l == h) {
                if(target > A[l]) return l+1;
                else return l;
            }
            
            int m = l + (h-l)/2;
            
            if(A[m] == target) return m;
            else if (target > A[m]) l = m+1;
            else h = m;
        }
    }
};
