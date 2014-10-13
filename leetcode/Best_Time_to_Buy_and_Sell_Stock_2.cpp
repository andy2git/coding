#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
       if(prices.size() <= 1) return 0;
       
       int mp = 0;
       for(int i = 1; i < prices.size(); i++){
           if(prices[i] > prices[i-1]){
               mp += prices[i] - prices[i-1];
           }
       }
       
       return mp;
    }
};

//-- test cases
int main(){
    Solution sol;
    {
        vector<int> stockPrices = {1};
        cout << sol.maxProfit(stockPrices) << endl;
    }

    {
        vector<int> stockPrices = {2, 1};
        cout << sol.maxProfit(stockPrices) << endl;
    }

    {
        vector<int> stockPrices = {1, 2, 4, 3, 2, 1, 6, 5};
        cout << sol.maxProfit(stockPrices) << endl;
    }
}
