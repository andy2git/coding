class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);
        
        for(int i = 0; ;i++){
            for(int j = 0; ;j++){
                if(j == m) return i;
                if(i+j == n) return -1;
                if(needle[j] != haystack[i+j]) break;
            }
        }
        
        return -1;
    }
};
