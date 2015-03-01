class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        if(nums.size() == 1) return {};
        
        vector<long long> result;
        vector<long long> rp;
        int n = nums.size();
        
        long long p = 1;
        for(int i = n-1; i >= 0; i--){
            p *= nums[i];
            rp.push_back(p);
        }
        reverse(rp.begin(), rp.end());
        
        p = 1;
        for(int i = 0; i < n; i++){
            if(i == n-1) result.push_back(p);
            else result.push_back(p*rp[i+1]);
            
            p *= nums[i];
        }
        
        return result;
    }
};
