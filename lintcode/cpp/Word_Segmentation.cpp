class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        if(s.empty() || dict.find(s) != dict.end()) return true;
        
        int n = s.size();
        vector<bool> t(n+1, false);
        t[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                string st = s.substr(j, i-j);
                if(t[j] && dict.find(st) != dict.end()){
                    t[i] = true;
                    break;
                }
            }
        }
        
        return t[n];
    }
};
