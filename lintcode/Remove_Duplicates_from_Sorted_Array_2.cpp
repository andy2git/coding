class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if(nums.size() <= 2) return nums.size();
        
        int cnt = 1;
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[j-1]){
                cnt = 1;
                nums[++i] = nums[j];
            }else{
                if(cnt < 2){
                    nums[++i] = nums[j];
                    cnt++;
                }
            }
        }
        
        return i+1;
    }
};
