/**
 * 
 *  Brute-force solution: start from each position, and see what is the longest substring you can get. 
 *   and if a duplicate is detected, we can safely skip i to the char after the duplicated char.
 * 
 * Solution: abcdcdab
 *           i   j
 *          m[0...255] -> keep what has been seen so far
 *
 * ---------------------------------------
 *    i  k     j
 * s[j] has a duplicate s[k] - so any [i+1,k] starting position cannot have a longer substring. 
 * So it is safe to skip the i all the way to k+1, also we need to unmask the elements in the mark[].
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        
        const int N = 256;
        vector<bool> mark(N, false);
        
        int i = 0;
        int j = 0;
        int maxLen = 0;
        for(; j < s.size(); j++){
            if(!mark[s[j]]) mark[s[j]] = true;
            else{
                maxLen = max(maxLen, j-i);
                while(s[i] != s[j]) {
                    mark[s[i++]] = false;
                }
                i++;
            }
        }
        
        maxLen = max(maxLen, j-i);
        
        return maxLen;
    }
};
