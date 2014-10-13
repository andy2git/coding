class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        
        vector<vector<int>> tbl(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(j == 0) tbl[i][j] = 1;
                if(i > 0 && j > 0){
                    if(S[i-1] == T[j-1]){
                        tbl[i][j] = tbl[i-1][j] + tbl[i-1][j-1];
                    }else{
                        tbl[i][j] = tbl[i-1][j];
                    }
                }
            }
        }
        
        return tbl[m][n];
    }
};
