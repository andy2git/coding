/**
 * One of the input strings could be empty, therefore we need empty row and column in the dynamic table
 * tbl[i][j]
 * i: 1->m
 *    j: 1->n
 * s1[0..... i-1.....m-1]
 * s2[0..... j-1.....n-1]
 * s3[0......i+j-1....m+n-1]
 *   
 * example:
 * s1: a s2: b s3: ab
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       // special cases
       if(s1.empty()) return s2 == s3;
       if(s2.empty()) return s1 == s3;
       if(s1.size() + s2.size() != s3.size()) return false;
       
       int m = s1.size();
       int n = s2.size();
       
       vector<vector<bool>> tbl(m+1, vector<bool>(n+1, false));
       
       for(int i = 0; i <= m; i++){
           for(int j = 0; j <= n; j++){
               if(i == 0 && j == 0) tbl[i][j] = true;
               else if(i == 0 && j > 0) tbl[i][j] = (s3[j-1] == s2[j-1]);
               else if(j == 0 && i > 0) tbl[i][j] = (s3[i-1] == s1[i-1]);
               else{
                   char t = s3[i+j-1];
                   if(t == s1[i-1]) tbl[i][j] = tbl[i-1][j] || tbl[i][j];
                   if(t == s2[j-1]) tbl[i][j] = tbl[i][j-1] || tbl[i][j];
               }
           }
       }
       
       return tbl[m][n];
    }
};
