class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int m = T.size();
        int n = S.size();
        
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) t[i][j] = 1;
                if(i > 0 && j > 0){
                    if(T[i-1] == S[j-1]) t[i][j] = t[i][j-1] + t[i-1][j-1];
                    else t[i][j] = t[i][j-1];
                }
            }
        }
        
        return t[m][n];
    }
};
