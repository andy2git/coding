class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;
        
        int p = 0;
        int q = p+1;
        int cnt = 1;
        
        while(q < n){
            if(A[p] == A[q]){
                cnt++;
                if(cnt == 2){
                   A[++p] = A[q++]; 
                }else q++;
            }else{
                A[++p] = A[q++];
                cnt = 1;
            }
        }
        
        return p+1;
    }
};
