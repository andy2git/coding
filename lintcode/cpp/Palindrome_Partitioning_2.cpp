class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        if(s.size() <= 1) return 0;
        int n = s.size();
        
        vector<int> t(n+1, 0);
        vector<vector<bool>> p(n, vector<bool>(n, false));
        
        fillPalindrome(s, p);
        
        for(int i = 1; i <= n; i++){
            int m = INT_MAX;
            for(int j = 0; j < i; j++){
                if(p[j][i-1]) m = min(m, t[j]+1);
            }
            
            t[i] = m;
        }
        
        return t[n]-1;
    }
private:
    void fillPalindrome(string &s, vector<vector<bool>> &p){
        int n = s.size();
        
        // i has to go from bottom up
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) p[i][j] = true;
                else if(j-i == 1){
                    p[i][j] = (s[i] == s[j]);
                }else{
                    p[i][j] = p[i+1][j-1] && (s[i] == s[j]);
                }
            }
        }
    }
};
