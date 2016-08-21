class Solution {
public:
    int jump(int A[], int n) {
        if(n <= 1) return 0;
        
        vector<int> step(n, 0);
        
        int m = 0;
        for(int i = 0; i < n; i++){
            if(i <= m){
                if(i+A[i] > m){
                    for(int j = m+1; j <= i+A[i]; j++){
                        if(j < n) step[j] = step[i]+1;
                    }
                    m = i + A[i];
                    if(m >= n-1) return step[n-1];
                }
            }
        }
        return 0;
    }
};
