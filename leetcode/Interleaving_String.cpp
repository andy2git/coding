class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1 == "") return s2 == s3;
        if(s2 == "") return s1 == s3;
        
        int m = s1.size();
        int n = s2.size();
        
        if(n+m != s3.size()) return false;
        
        vector<vector<bool>> tbl(m+1, vector<bool>(n+1, false));
        tbl[0][0] = true;
        
        for(int j = 1; j <= n; j++){
            if(s2[j-1] == s3[j-1]) tbl[0][j] = true;
        }
        for(int i = 1; i <= m; i++){
            if(s1[i-1] == s3[i-1]) tbl[i][0] = true;
        }
        
        int k;
        for(int i = 1; i <=m; i++){
            for(int j = 1; j<=n; j++){
                k = i+j-1;
                if(s1[i-1] == s3[k] && s2[j-1] != s3[k]){
                    tbl[i][j] = tbl[i-1][j];
                }else if(s1[i-1] != s3[k] && s2[j-1] == s3[k]){
                    tbl[i][j] = tbl[i][j-1];
                }else if(s1[i-1] == s3[k] && s2[j-1] == s3[k]){
                    tbl[i][j] = tbl[i-1][j] || tbl[i][j-1];
                }else{
                    tbl[i][j] = false;
                }
            }
        }
        return tbl[m][n];
    }
};
