class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n <= 0) return 0;
        int i = 0;
        int j = 0;
        
        while(j < n){
            if(A[j] == elem) j++;
            else A[i++] = A[j++];
        }
        
        return i;
    }
};
