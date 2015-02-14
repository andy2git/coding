class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        if(nums.size() < 3) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        int n = nums.size();
        for(int i = 0; i <= n-3; i++){
            //move i to the next non-identical element
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            while(j < k){
                int s = nums[i]+nums[j]+nums[k];
                if(s > 0) k--;
                else if(s < 0) j++;
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // move j to the next non-idential element
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                    // move k to the next non-idential element
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                }
            }
        }
        
        return result;
    }
};

