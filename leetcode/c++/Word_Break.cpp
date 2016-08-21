/**
 * Another solution is to keep track of all possible s[i->j] in tbl[i][j]
 *
 * Memoization solution: 
 *    - m[i]: work breakable starting from i to the end of the string s
 * 
 * DP solution: M[i]: is word breakable for s[0..i].
 *              M[i] = any j that {M[j] && dict.contains(s[j,i]}
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
        // i is the index for vector<int> M
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

/**
 * Solution#2: using matrix to store all the possible words inside s.
 * For the backtrack, the worst case is O(n!)
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s == "") return true;
        
        // init the tbl
        int n = s.size();
        vector<vector<bool>> tbl(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dict.find(s.substr(i, j-i+1)) != dict.end()) tbl[i][j] = true;
            }
        }
        
        return backtrack(tbl, n-1);
    }
    
private:
    bool backtrack(vector<vector<bool>> &tbl, int k){
        if(k < 0) return true;
    
        for(int i = 0; i <= k; i++){
            if(tbl[i][k]){
                if(backtrack(tbl, i-1)) return true;
            }
        }
        return false;
    }
};

