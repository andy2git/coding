class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) return haystack;
        if(!*haystack) return nullptr;
        
        int len = 0;
        char *r = needle;
        while(*r){
            len++;
            r++;
        }
        
        char *h = haystack;
        while(*h){
            char *p = h;
            if(!is_valid(p, len)) break;
            char *q = needle;
            
            while(*p && *q){
                if(*p == *q) {
                    p++;
                    q++;
                }else{
                    break;
                }
            }
            if(!*q) return h;
            
            h++;
        }
        
        return nullptr;
    }
private:
    bool is_valid(char *p, int steps){
        
        while(steps > 1){
            p++;
            if(!*p) return false;
            steps--;
        }
        return true;
    }
};
