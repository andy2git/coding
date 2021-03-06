/**
 * Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit. 
 *
 */ 

/**
 * http://dpcoffee.blogspot.com/2013/11/notes-on-dynamic-programming-work-in.html
 *
 * Observations: the stock can be sold after it was purchased first. So the problem becomes finding a pair of elements with the max difference. 
 * The max difference is not necessary generated by the min or max elements of the input array. So finding the min/max does not help in this case.
 *
 * For example, Given an input array: (7,6,5,4,2,5,4,3,2,1). The expected output: (7,6,5,4,2,5,4,3,2,1). So the problem can be mapped to max subarray problem. 
 *
 * Variations: if you are trying to find a pair with the least profit. You can negate the numbers, and apply the same algorithm.
 *
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        
        vector<int> diff(prices.size());
        adjacent_difference(prices.begin(), prices.end(), diff.begin());
        
        int sum = 0; 
        int max_sum = 0;
        
        // Observation: all max subarray must end with a[i]
        // 
        // s[i] = max(s[i-1] + a[i], a[i], 0)
        // s[i]: max subarray including a[i]
        // ---------------------------------
        //   1. prefix of s[i] cannot be < 0
        //   2. use max_sum to keep track the largest subarray
        for(int i = 1; i < diff.size(); i++){
            sum += diff[i];
            if(sum < 0){
                sum = 0;
            }else{
                if(sum > max_sum){
                    max_sum = sum;
                }
            }
        }
        
        return max_sum;
    }
};
