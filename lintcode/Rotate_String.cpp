class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if(A.size() == 0) return "";
        
        int n = A.size();
        offset %= n;
        
        int i = n-1;
        int x = A[i];
        int end = n-1;
        int cnt = 1;
        
        while(cnt < n || i != end){
            if(i == end){
                i--;
                x = A[i];
                end = i;
            }
            
            int j = (i-offset+n)%n;
            
            if(j == end) A[i] = x;
            else swap(A[i], A[j]);
            
            i = j;
            cnt++;
        }
        
        return A;
    }
};


