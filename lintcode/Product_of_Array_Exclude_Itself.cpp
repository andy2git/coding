/* Solution: this is the brute-force solution, which runs in O(n^2) */

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if(nums.size() == 1) return {};
        
        vector<long long> result;
        
        for(int i = 0; i < nums.size(); i++){
            result.push_back(prodHelper(nums, i));
        }
        return result;
    }
private:
    long long prodHelper(vector<int> &nums, int ind){
        long long prod = 1;
        for(int i = 0; i < nums.size(); i++){
            if(ind != i) prod *= nums[i];
        }
        
        return prod;
    }
};

/* Solution#2: DP solution */
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if(nums.size() == 1) return {};
        
        vector<long long> result;
        vector<long long> lp;
        vector<long long> rp;
        int n = nums.size();
        
        long long p = 1;
        for(int i = 0; i < n; i++){
            p *= nums[i];
            lp.push_back(p);
        }
        
        p = 1;
        for(int i = n-1; i >= 0; i--){
            p *= nums[i];
            rp.push_back(p);
        }
        reverse(rp.begin(), rp.end());
        
        for(int i = 0; i < n; i++){
            if(i == 0) result.push_back(rp[1]);
            else if(i == n-1) result.push_back(lp[n-2]);
            else{
                result.push_back(lp[i-1]*rp[i+1]);
            }
        }
        
        return result;
    }
};
