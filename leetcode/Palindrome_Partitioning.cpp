/* similar problem from lintcode: http://www.lintcode.com/en/problem/palindrome-partitioning-ii/ */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s == "") return vector<vector<string>>();
        
        vector<vector<string>> result;
        vector<string> t;
        partition_helper(result, t, s);
        
        return result;
    }
    
private:
    void partition_helper(vector<vector<string>> &result, vector<string> &sofar, string rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        string w;
        for(int i = 0; i < rest.size(); i++){
            w = rest.substr(0, i+1);
            if(is_pal(w)){
                sofar.push_back(w);
                partition_helper(result, sofar, rest.substr(i+1));
                sofar.pop_back();
            }
        }
    }
    
    bool is_pal(string &st){
        int i = 0;
        int j = st.size()-1;
        
        while(i < j){
            if(st[i] != st[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

/* DP solution */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        
        int maxLen = INT_MIN;
        int ind = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) t[i][j] = true;
                else if(j == i+1) t[i][j] = (s[i]==s[j]);
                else t[i][j] = t[i+1][j-1] && (s[i]==s[j]);
                
                int len = j-i+1;
                if(len > maxLen && t[i][j]) {
                    maxLen = len;;
                    ind = i;
                }
            }
        }
        
        return s.substr(ind, maxLen);
       
    }
};
