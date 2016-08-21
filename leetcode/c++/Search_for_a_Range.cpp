/**
 * Guaranteed O(lgn) solution
 *
 */
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        
        int lower = lower_bound(A, n, target);
        int upper = upper_bound(A, n, target);
        
        result.push_back(lower);
        result.push_back(upper);
        
        return result;
    }

private:
    int lower_bound(int A[], int n, int target){
        if(n <= 0) return -1;
        
        int l = 0;
        int h = n-1;
        int m;
        int lower = INT_MAX;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target){
                if(m < lower) lower = m;
                h = m-1;
            }else if(A[m] < target) l = m+1;
            else h = m-1;
        }
        
        if(lower != INT_MAX) return lower;
        else return -1;
    }
    
    int upper_bound(int A[], int n, int target){
        if(n <= 0) return -1;
        
        int l = 0;
        int h = n-1;
        int m;
        int upper = INT_MIN;
        
        while(l <= h){
            m = l + (h-l)/2;
            if(A[m] == target){
                if(m > upper) upper = m;
                l = m+1;
            }else if(A[m] < target) l = m+1;
            else h = m-1;
        }
        
        if(upper != INT_MIN) return upper;
        else return -1;
    }
};

/**
 * This solution has O(n) time complexity if all the elements are the same in the array
 * Please refer to the previous solution for guaranteed O(lgn) solution
 */
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
