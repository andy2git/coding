class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        if(nums.size() < 3) throw runtime_error("wrong input");
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int minDis = INT_MAX;
        int result;
        
        for(int i = 0; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                
                // for each candidate, find the closest one
                int dis = abs(sum - target);
                if(dis < minDis) {
                    minDis = dis;
                    result = sum;
                }
                
                if(sum < target) j++;
                else k--;
            }
        }
        
        return result;
    }
};
