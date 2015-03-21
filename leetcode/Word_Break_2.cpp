class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return {};

        // init the tbl
        int n = s.size();
        vector<vector<bool>> tbl(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dict.find(s.substr(i, j-i+1)) != dict.end()) tbl[i][j] = true;
            }
        }
        
        //check first row and last column to avoid cases where there is no valid output,
        // but the intermidate output could be large
        int i = 0;
        for( i = 0; i < n; i++){
            if(tbl[0][i]) break;
        }
        if(i == n) return {};
            
        for(i=0; i<n;i++){
            if(tbl[i][n-1]) break;
        }
        if(i == n) return {};
    
        vector<string> result;
        backtrack(result, "", s, tbl, n-1);
        return result;
    }
private:
    void backtrack(vector<string> &result, string sofar, string &s, vector<vector<bool>> &tbl, int k){
        if(k < 0) {
            result.push_back(sofar.substr(1, sofar.size()));
            return;
        }
        
        for(int i = 0; i <= k; i++){
            if(tbl[i][k]){
                backtrack(result, " "+s.substr(i, k-i+1)+sofar, s, tbl, i-1);
            }
        }
    }
};
