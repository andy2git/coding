class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> tbl(m+1, vector<int>(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) tbl[i][j] = j;
                if(j == 0) tbl[i][j] = i;
                
                if(i > 0 && j > 0){
                    if(word1[i-1] == word2[j-1]){
                        tbl[i][j] = tbl[i-1][j-1];
                    }else{
                        tbl[i][j] = min(min(tbl[i-1][j-1], tbl[i-1][j]), tbl[i][j-1])+1;
                    }
                }
            }
        }
        
        return tbl[m][n];
    }
};
