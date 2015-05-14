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

// backtracking solution
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty() || dict.empty()) return {};
        
        
        if(!containsSolution(s, dict)) return{};
        
        vector<string> result;
        wbHelper(result, "", s, 0, dict);
        return result;
    }
    
private:
    bool containsSolution(string &s, unordered_set<string> &dict){
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(dict.find(s.substr(i, n-i)) != dict.end()) return true;
        }
        
        return false;
    }
    
    
    void wbHelper(vector<string> &result, string sofar, string remain, int s, unordered_set<string> &dict){
        if(s == remain.size()){
            if(!sofar.empty()) result.push_back(sofar.substr(1));
            return;
        }
        
        for(int i = s; i < remain.size(); i++){
            string t = remain.substr(s, i-s+1);
            if(dict.find(t) != dict.end()){
                wbHelper(result, sofar+" "+t, remain, i+1, dict);
            }
        }
    }
};
