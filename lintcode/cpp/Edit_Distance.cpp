class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m ; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) t[i][j] = j;
                if(j == 0) t[i][j] = i;
                if(i > 0 && j > 0){
                    if(word1[i-1] == word2[j-1]) t[i][j] = t[i-1][j-1];
                    else t[i][j] = min(t[i-1][j-1], min(t[i-1][j], t[i][j-1]))+1;
                }
            }
        }
        
        return t[m][n];
    }
};
