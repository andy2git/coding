class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        
        int n = s.size();
        vector<vector<bool>> tbl(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++){
            tbl[i][i] = true;
        }
        
        int max_len = 1;
        int s_ind = 0;
        
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) {
                tbl[i][i+1] = true;
                max_len = 2;
                s_ind = i;
            }else{
                tbl[i][i+1] = false;
            }
        }
        
        int j;
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                j = i + len -1;
                
                if(s[i] == s[j] && tbl[i+1][j-1]){
                    tbl[i][j] = true;
                    if(len > max_len){
                        max_len = len;
                        s_ind = i;
                    }
                }else{
                    tbl[i][j] = false;
                }
            }
        }
        
        return s.substr(s_ind, max_len);
    }
};

