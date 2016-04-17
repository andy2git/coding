class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        
        vector<int> d(prices.size()-1, 0);
        for(int i = 1; i < prices.size(); i++) d[i-1] = prices[i]-prices[i-1];
        
        int n = d.size();
        vector<int> ml(n+1, 0);
        int pre = 0;
        for(int i = 1; i <= n; i++){
            int t = max(max(0, d[i-1]), pre+d[i-1]);
            ml[i] = max(ml[i-1], t);
            pre = t;
        }
        
        int mp = ml[n];
        pre = 0;
        int ms = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            int t = max(max(0, d[i]), pre+d[i]);
            ms = max(t, ms);
            pre = t;
            if(ms + ml[i] > mp) mp = ms + ml[i];
        }
        
        return mp;
    }
};
