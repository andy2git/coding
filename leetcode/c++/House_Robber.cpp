class Solution {
public:
    int rob(vector<int> &num) {
        if(num.empty()) return 0;
        
        int n = num.size();
        vector<int> t(n+1, 0);
        t[0] = 0;
        t[1] = num[0];
        
        for(int i = 1; i <= n; i++){
            t[i] = max(t[i-1], t[i-2]+num[i-1]);
        }
        
        return t[n];
    }
};
