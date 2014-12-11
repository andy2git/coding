/**
 * Solution: abcdcdab
 *           i   j
 *          m[0...255] -> keep what has been seen so far
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        
        vector<bool> m(256, false);
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN;
        while(j < s.length()){
            if(m[s[j]] == false){
                m[s[j++]] = true;
            }else{
                maxLen = max(maxLen, j-i);
                while(s[i] != s[j]){
                    m[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }
        }
        
        return max(maxLen, j-i);
    }
};
