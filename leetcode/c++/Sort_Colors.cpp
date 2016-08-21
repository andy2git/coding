class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1) return;
        
        int i = 0;
        int j = 0;
        int k = n-1;
        
        while(j <= k){
            if(A[j] == 0){
                swap(A[i], A[j]);
                i++;
                j++;
            }else if(A[j] == 1){
                j++;
            }else{
                swap(A[j], A[k]);
                k--;
            }
        }
    }
};
