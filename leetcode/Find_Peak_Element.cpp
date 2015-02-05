/**
 * Solution#1: After padding, we will have at least 3 elems in the input.
 *             Also if we have one elem, then it will be at least one peak.
 *             so A[m-1] and A[m+1] will not be out of index.
 *
 * Notes: padding takes O(n) time
 * 
 * Solution#2: write comp funciton to handle the speical case where m-1 or m+1 are out of index.
 */
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if(n == 0) throw runtime_error("no element!");
        
        int l = 0;
        int h = n-1;
        int m;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(isBigger(num, m, m-1) && isBigger(num, m, m+1)) return m;
            else if(!isBigger(num, m, m-1)) h = m-1;
            else l = m+1;
        }
        
        throw runtime_error("should not be here!");
    }
private:
    bool isBigger(const vector<int> &num, int a, int b){
        if(b < 0 || b >= num.size()) return true;
        else return num[a] > num[b];
    }
};

/* Another extension of this problem is the peak in 2-D space */
