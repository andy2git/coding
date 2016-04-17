class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        if(nums.size() < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for(int i = 0; i < n-3; i++){
            // skip duplicated i except the first time
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i+1; j < n-2; j++){
                // skip duplicated j except the first time
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int p = j+1;
                int q = n-1;
                
                while(p < q){
                    int sum = nums[i] + nums[j] + nums[p] + nums[q];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        while(p < q && nums[p] == nums[p-1]) p++;
                        q--;
                        while(q > p && nums[q] == nums[q+1]) q--;
                    }else if (sum < target){
                        p++;
                    }else {
                        q--;
                    }
                }
            }
        }
        
        return result;
        
    }
};

