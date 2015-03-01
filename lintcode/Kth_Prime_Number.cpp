class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        if(k <= 0) throw runtime_error("invalid input!");
        
        vector<long long> nums;
        nums.push_back(1);
        int p3 = 0;
        int p5 = 0;
        int p7 = 0;
        
        for(int i = 1; i <= k; i++){
            long long x = min(min(3*nums[p3], 5*nums[p5]), 7*nums[p7]);
            nums.push_back(x);
            
            if(x%3 == 0) p3++;
            if(x%5 == 0) p5++;
            if(x%7 == 0) p7++;
        }
        
        return nums[k];
    }
};
