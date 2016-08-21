class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt = 0;
        
        while(*s){
            while(*s && *s == ' ') s++;
            
            if(*s) cnt = 0;
            else return cnt;
            
            while(*s && isalpha(*s)){
                s++;
                cnt++;
            }
        }
        
        return cnt;
    }
};
