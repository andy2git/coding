
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0) return false;
        
        int l = 0;
        int h = n-1;
        
        while(l <= h){
            int m = l + (h-l)/2;
            if(A[m] == target) return true;
            
            if(A[m] < A[h]){
                if(target >= A[m] && target <= A[h]) l = m+1;
                else h = m-1;
            }else if(A[m] == A[h]){
                h--;
            }else{
                if(target >= A[l] && target <= A[m]) h = m-1;
                else l = m + 1;
            }
        }
        
        return false;
    }
};
