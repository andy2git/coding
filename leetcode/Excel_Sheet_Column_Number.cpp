class Solution {
public:
    int titleToNumber(string s) {
        if(s == "") throw runtime_error("empty input!");
        
        int result = 0;
        int base = 1;
        for(int i = s.size()-1; i >= 0; i--){
            result =(s[i]-'A'+1)*base  + result;
            base *= 26;
        }
        
        return result;
    }
};
