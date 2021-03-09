// mention the brute force way.
// move element one by one
class Solution {
    public void rotate(int[] nums, int k) {
        if(nums == null || nums.length == 0) return;
        
        int n = nums.length;
        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
    
    private static void reverse(int[] A, int s, int e) {
        while(s < e) {
            swap(A, s++, e--);
        }
    }
    
    private static void swap(int[] A, int x, int y) {
        int t = A[x];
        A[x] = A[y];
        A[y] = t;
    }
}
