class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        int maxLen = 1;
        int sInd = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            if(i > 0){
                find_max_palin(s, i-1, i+1, 1, maxLen, sInd);
            }
            
            find_max_palin(s, i, i+1, 0, maxLen, sInd);
        }
        
        return s.substr(sInd, maxLen);
    }
private:
    void find_max_palin(string &s, int j, int k, int len, int &maxLen, int &sInd){
        int n = s.length();
        while(j >= 0 && k < n){
            if(s[j] == s[k]){
                len += 2;
                j--; k++;
            }else {
                if(len > maxLen){
                    maxLen = len;
                    sInd = j+1;
                }
                break;
            }
        }
        
        if(len > maxLen){
            maxLen = len;
            sInd = j+1;
        }
    }
};
