class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if(n <= 0) return {-1, -1};
        
        int l = 0;
        int h = n-1;
        int m;
        int x, y;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target){
                x = y = m;
                while(x >=0 && A[x] == target) x--;
                while(y < n && A[y] == target) y++;
                return {x+1, y-1};
            }else if(A[m] < target){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return {-1,-1};
    }
};
