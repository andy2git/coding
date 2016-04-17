class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        
        int l = 0;
        int h = array.size()-1;
        return binarySearchHelper(array, l, h, target);
    }
private:
    int binarySearchHelper(vector<int> &A, int s, int e, int x){
        if(s > e) return -1;
        
        int m = s + (e-s)/2;
        if(A[m] < x) return binarySearchHelper(A, m+1, e, x);
        else if(A[m] > x) return binarySearchHelper(A, s, m-1, x);
        else{
            int t = binarySearchHelper(A, s, m-1, x);
            if(t == -1) return m;
            else return t;
        }
    }
};


