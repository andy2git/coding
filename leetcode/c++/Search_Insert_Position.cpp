class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int h = n-1;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target) return m;
            else if(A[m] < target) l = m+1;
            else h = m-1;
        }
        
        return l;
    }
};
