class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1) return n;
        
        int i = 0;
        int j = 1;
        
        while(j < n){
            if(A[i] == A[j]){
                j++;
            }else{
                A[++i] = A[j++];
            }
        }
        return i+1;
    }
};
