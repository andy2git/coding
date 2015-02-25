class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cand;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cand = nums[i];
                cnt = 1;
            }else{
                if(cand == nums[i]) cnt++;
                else cnt--;
            }
        }
        
        return cand;
    }
};
