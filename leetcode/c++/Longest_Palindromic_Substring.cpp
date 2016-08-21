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
        if(s.size() <= 1) return s;
        int maxLen = INT_MIN;
        int maxInd = 0;
        
        for(int i = 0; i < s.size(); i++){
            int len = palindromeHelper(s, i-1, i+1, 1);
            if(len > maxLen){
                maxInd = i;
                maxLen = len;
            }
            
            len = palindromeHelper(s, i-1, i, 0);
            if(len > maxLen){
                maxInd = i;
                maxLen = len;
            }
        }
        
        return s.substr(maxInd-maxLen/2, maxLen);
    }
private:
    int palindromeHelper(string &st, int s, int e, int len){
       if(s < 0 || e >= st.size()) return len;
       
       int maxLen = INT_MIN;
       while(s>=0 && e<st.size() && st[s]==st[e]){
           len += 2;
           s--;
           e++;
       }
       maxLen = max(maxLen, len);

       return maxLen;
    }
};
