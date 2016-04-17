class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int i = 0;
        int j = nums.size()-1;
        
        while(i <= j){
            if(nums[i] < k) i++;
            else swap(nums[i], nums[j--]);
        }
        
        return i;
    }
};
