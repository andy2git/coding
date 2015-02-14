class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        
        vector<vector<int>> tbl(m, vector<int>(n, 0));
        int maxLen = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 if(i == 0 || j == 0) tbl[i][j] = (A[i] == B[j])? 1 : 0;
                 
                 if(i > 0 && j > 0){
                     if(A[i] == B[j]) tbl[i][j] = tbl[i-1][j-1] +1;
                     else tbl[i][j] = 0;
                 }
                 
                 if(tbl[i][j] > maxLen) maxLen = tbl[i][j];
            }
        }
        
        return maxLen;
    }
};


