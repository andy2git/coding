/**
 * Another solution is to keep track of all possible s[i->j] in tbl[i][j]
 *
 * Memoization solution: 
 *    - m[i]: work breakable starting from i to the end of the string s
 * 
 * DP solution:
 *
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return true;
        if(dict.find(s) != dict.end()) return true;
     
        int n = s.length();
        vector<bool> M(n+1, false);
        M[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(M[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    M[i] = true;
                    break;
                }
            }
        }
     
        return M[n];
    }
};

