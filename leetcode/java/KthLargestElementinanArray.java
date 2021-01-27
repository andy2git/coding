class Solution {
    public int findKthLargest(int[] nums, int k) {
        if(nums == null || nums.length == 0) throw new IllegalArgumentException("xx");
        return flh(nums, 0, nums.length-1, k);
        
    }

    public int flh(int[] A, int s, int e, int k) {
        // solution can always be found, so it will never hit here
        if(s > e) throw new IllegalArgumentException("xx");
            
        int p = partation(A, s, e);
        int r = p-s+1;
        if(r == k) return A[p];
        else if (k < r) return flh(A, s, p-1, k);
        else return flh(A, p+1, e, k-r);
    }
    
    private int partation(int[] A, int s, int e) {
        int i = s;
        int j = s;
        while(j <= e) {
            if(A[j] >= A[s]) swap(A, i++, j++);
            else j++;
        }
        swap(A, s, i-1);
        return i-1;
    }
    
    private void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        return kthHelper(nums, 0, nums.length-1, k);
    }
    
    private int kthHelper(int[] A, int s, int e, int k) {
        // solution can always be found, so it will never hit here
        // if(s > e) throw new IllegalArgumentException("xx");

        // base case
        if(s > e) return -1;
        
        int p = partition(A, s, e);
        // figure out ranking in range [s, e]
        int r = p - s + 1;
        if(k == r) return A[p];
        else if (k < r) return kthHelper(A, s, p-1, k);
        else return kthHelper(A, p+1, e, k-r);
    } 
    
    // |>=x       |<x|
    //     i     j
    private int partition(int[] A, int s, int e) {
        int i = s+1;
        int j = e;
        int p = A[s];
        while(i <= j) {
            if(A[i] >= p) i++;
            else swap(A, i, j--);
        }
        swap(A, s, j);
        return j;
    }
    
    private void swap(int[] A, int x, int y) {
        int t = A[x];
        A[x] = A[y];
        A[y] = t;
    }
    
}
