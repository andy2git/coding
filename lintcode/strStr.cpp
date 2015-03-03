class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(char *source, char *target) {
        if(!target) return -1;
        if(*target == '\0') return 0;
        if(!source || *source == '\0') return -1;
    
        char *p = source;
        char *k = nullptr;
        char *q = target;
    
        while(*p){
            k = p;
            while(*k != '\0' && *q !='\0' && *(k++) == *(q++));
            if(*q == '\0') return p-source;
            else{
                q = target;
                p++;;
            }
        }
    
        return -1;
    }
};
