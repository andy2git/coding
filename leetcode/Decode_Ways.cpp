class Solution {
public:
    int numDecodings(string s) {
        if(s == "" || s[0] == '0') return 0;
        if(s.size() == 1) return 1;
          
        vector<int> dp(s.size()+1);
        dp[s.size()] = 1;
          
        for(int j = s.size()-1; j>=0; j--){
            if(s[j] == '0') {
                dp[j] = 0;
                continue;
            }

            if(j < s.size()-1 && atoi(s.substr(j, 2).c_str()) <= 26){
                dp[j] = dp[j+1] + dp[j+2];
            }else{
                dp[j] = dp[j+1];
            }
        }
        return dp[0];
    }
};
