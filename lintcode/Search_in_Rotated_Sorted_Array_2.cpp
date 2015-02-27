class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        if(A.empty()) return false;

        int l = 0;
        int h = A.size()-1;

        while(l <= h){
            int m = l + (h-l)/2;

            if(A[m] == target) return true;

            if (A[l] < A[m]){
                if(target >= A[l] && target < A[m]) h = m-1;
                else l = m+1;
            }else if(A[l] > A[m]){
                if(target > A[m] && target <= A[h]) l = m+1;
                else h = m-1;
            }else {
                l++;
            }
        }

        return false;
    }
};
