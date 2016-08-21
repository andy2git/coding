/**
 * Best Time to Buy and Sell Stock III
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Variation: you may complete at most three transactions. 
 * |<------------------>|<-------->|<------->|
 * |<------------------ i -------- j ------->|
 */
 
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        
        vector<int> diff((int)prices.size()-1);
        
        for(int i = 1; i < prices.size(); i++){
            diff[i-1] = prices[i] - prices[i-1];
        }
        
        int max_sum = 0;
        int sum = 0;
        vector<int> mp(diff.size(), 0);
        
        for(int i  = 0; i < diff.size(); i++){
            sum += diff[i];
            if(sum < 0) sum = 0;
            if(sum > max_sum) {
                max_sum = sum;
            }
            
            mp[i] = max_sum;
        }
        
        max_sum = mp[diff.size()-1];
        sum = 0;
        for(int i = diff.size()-1; i > 0; i--){
            sum += diff[i];
            if(sum < 0) sum = 0;
            if(sum + mp[i-1] > max_sum){
                max_sum = sum + mp[i-1];
            }
        }
        return max_sum;
    }
};

class Solution_2 {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        
        std::size_t N = prices.size();
        vector<int> diff(N);
        adjacent_difference(prices.begin(), prices.end(), diff.begin());
        diff[0] = 0;
        
        //the first elem in mpL, mpR is not used
        vector<int> mpL(N, 0);
        vector<int> mpR(N, 0);
        
        find_max_sub(diff.begin(), diff.end(), mpL.begin());
        find_max_sub(diff.rbegin(), diff.rend(), mpR.rbegin());
        
        int mp = mpL[mpL.size()-1];
        for(int i = 1; i < mpL.size()-1; i++){
            int t = mpL[i] + mpR[i+1];
            if(t > mp){
                mp = t;
            }
        }
        
        return mp;
    }
private:
    template<typename T, typename U>
    void find_max_sub(T bIt, T eIt, U dIt){
        int sum = 0;
        int max_sum = 0;
        
        for(T it = bIt; it != eIt; ++it){
            sum += *it;
            if(sum < 0) sum = 0;
            if(sum > max_sum) max_sum = sum;
            *dIt++ = max_sum;
        }
    }
};

int main(){
    Solution_2 sol2;
    vector<int> sp = {1,2,4,1,2};

    int mp = sol2.maxProfit(sp);
    cout << "max profit:" << mp << endl;
}
