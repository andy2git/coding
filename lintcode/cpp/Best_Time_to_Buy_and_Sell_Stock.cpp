class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.size() <= 1) return 0;
        
        int n = prices.size();
        vector<int> diff(n-1, 0);
        for(int i = 1; i < n; i++){
            diff[i-1] = prices[i] - prices[i-1];
        }
        
        return maxSubSum(diff);
    }
    
private:
    int maxSubSum(vector<int> &A){
        
        int n = A.size();
        vector<int> s(n, 0);
        s[0] = max(0, A[0]);
        int maxSum = s[0];
        
        for(int i = 1; i < n; i++){
            s[i] = max(0, max(s[i-1]+A[i], A[i]));
            if(s[i] > maxSum) maxSum = s[i];
        }
        return maxSum;
    }
};

