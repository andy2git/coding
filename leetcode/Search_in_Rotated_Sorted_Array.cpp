class Solution {
public:
    int search(int A[], int n, int target) {
        if(n <= 0) return -1;
        
        int l = 0;
        int h = n-1;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            
            if(A[m] == target) return m;
            
            if(A[l] <= A[m]){
                if(A[m] < target) l = m+1;
                else if(A[m] > target){
                    if(target > A[l]) h = m-1;
                    else if(target == A[l]) return l;
                    else l = m+1;
                }
            }else{
                if(A[m] < target){
                    if(target < A[h]) {
                        l = m+1;
                        h--;
                    }else if(target == A[h]){
                        return h;
                    }else{
                        h = m-1;
                    }
                }else{
                    h = m-1;
                }
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        if(n <= 0) return -1;
        
        int l = 0;
        int h = n-1;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target) return m;
            
            if(A[l] <= A[m]){ //l and m might point to the same element for [2, 1] case
                if(A[l] == target) return l;
                if(target < A[m] && target > A[l]) h = m-1;
                else l = m+1;
            }else if(A[l] > A[m]){
                if(A[h] == target) return h;
                if(target > A[m] && target < A[h]) l = m+1;
                else h = m-1;
            }
        }

        return -1;
    }
};
