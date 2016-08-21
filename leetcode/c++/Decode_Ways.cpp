class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        
        vector<int> t(n+1, 0);
        t[0] = 1;
        
        for(int i = 1; i <= n; i++){
            if(s[i-1] != '0') t[i] += t[i-1];
            if(isValid(s, i-2)) t[i] += t[i-2];
        }
        
        return t[n];
    }
private:
    int isValid(string &s, int i){
        if(i < 0) return false;
        
        int x = stoi(s.substr(i, 2));
        if(x >= 10 && x <= 26) return true;
        else return false;
    }
};
