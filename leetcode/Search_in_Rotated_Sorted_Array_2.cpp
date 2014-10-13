class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0) return false;
        
        int l = 0;
        int h = n-1;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target) return true;
            
            if(A[l] < A[m]){
                if(A[l] == target) return true;
                if(target < A[m] && target > A[l]) h = m-1;
                else l = m+1;
            }else if(A[l] > A[m]){
                if(A[h] == target) return true;
                if(target > A[m] && target < A[h]) l = m+1;
                else h = m-1;
            }else{
                l++;
            }
        }
        
        return false;
    }
};
