class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if(A.empty()) return -1;
        
        int l = 0;
        int h = A.size()-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            
            if(A[m] == target) return m;
            
            if (A[l] < A[m]){
                if(target >= A[l] && target < A[m]) h = m-1;
                else l = m+1;
            }else{
                if(target > A[m] && target <= A[h]) l = m+1;
                else h = m-1;
            }
        }
        
        return -1;
    }
};
