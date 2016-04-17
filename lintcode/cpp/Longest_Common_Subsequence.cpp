class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A == "" || B == "") return 0;
        int m = A.size();
        int n = B.size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) t[i][j] = (A[i] == B[j])?1:0;
                if(i > 0 && j > 0){
                    if(A[i] == B[j]) t[i][j] = t[i-1][j-1] +1;
                    else t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[m-1][n-1];
    }
};



