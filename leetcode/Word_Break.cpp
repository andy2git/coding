/**
 * Another solution is to keep track of all possible s[i->j] in tbl[i][j]
 *
 * Memoization solution: 
 *    - m[i]: work breakable starting from i to the end of the string s
 * 
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return true;
        if(dict.find(s) != dict.end()) return true;
        
        vector<int> m(s.length(), -1);
        
        m[0] = wb_helper(s, 0, dict, m);
        
        return m[0] > 0;
    }
private:
    int wb_helper(string &s, int sInd, unordered_set<string> &dict, vector<int> &m){
        if(sInd >= s.length()) return 1;
        if(dict.find(s.substr(sInd)) != dict.end()) {
            m[sInd] = 1;
            return 1;
        }
        
        for(int i = sInd; i < s.length(); i++){
            if(dict.find(s.substr(sInd, i-sInd+1)) != dict.end()){
                if(m[i+1] == -1) {
                    m[i+1] = wb_helper(s, i+1, dict, m);
                }
                if(m[i+1] == 1) return 1;
            }
        }
        
        return 0;
    }
};

