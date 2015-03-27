class Solution {
public:
    int atoi(string s) {
        int sign = 1;
        
        int i = 0;
        int n = s.size();
        
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i] == '+') i++;
        else if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        
        int result = 0;
        const int MAX_DIV = INT_MAX/10;
        while(i < n && isdigit(s[i])){
            int d = s[i] - '0';
            if(result > MAX_DIV || (result == MAX_DIV && d >= 8)) return (sign == 1?INT_MAX:INT_MIN);
            
            result = result*10 + d;
            i++;
        }
        
        return result*sign;
    }
};
