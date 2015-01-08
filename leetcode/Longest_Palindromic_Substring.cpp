/**
 * Brute force solution: there are O(n^2) substrings, and each palindrom check take O(n) => O(n^3)
 * 
 * Solution: There are 2n-1 possible starting position for longest palindrom string, and this will leads to O(n^2) solution
 *        ----aa----
 *         j--><--k
 *
 *        ----aba----
 *         j-->-<-k
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        int maxLen = 1;
        int sInd = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            find_max_palin(s, i-1, i+1, 1, maxLen, sInd);
            find_max_palin(s, i, i+1, 0, maxLen, sInd);
        }
        
        return s.substr(sInd, maxLen);
    }
private:
    void find_max_palin(string &s, int j, int k, int len, int &maxLen, int &sInd){
        int n = s.length();
        if(j < 0 || k >= n) return;
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
