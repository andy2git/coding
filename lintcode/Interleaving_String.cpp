/**
 * DP:
 * s1[0..... i-1.....m-1]
 * s2[0..... j-1.....n-1]
 * s3[0......i+j-1....m+n-1]
 * 
 * t[i][j]: s1[0..i-1] and s2[0..j-1] can be used to interleave string s3.
 */
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.empty()) return s2 == s3;
        if(s2.empty()) return s1 == s3;
        if(s1.size() + s2.size() != s3.size()) return false;
        
        int m = s1.size();
        int n = s2.size();
        vector<vector<bool>> t(m+1, vector<bool>(n+1, false));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0) t[i][j] = true;
                if(i == 0 && j > 0){
                    t[i][j] = t[i][j-1] && (s2[j-1]==s3[j-1]);
                }
                if(j == 0 && i > 0){
                    t[i][j] = t[i-1][j] && (s1[i-1]==s3[i-1]);
                }
                if(i > 0 && j > 0){
                    if(s1[i-1] == s3[i+j-1]) t[i][j] = t[i-1][j] || t[i][j];
                    if(s2[j-1] == s3[i+j-1]) t[i][j] = t[i][j-1] || t[i][j];
                }
            }
        }
        
        return t[m][n];
    }
};
