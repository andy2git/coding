class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 1) return;
        
        int i = 1;
        for(; i < nums.size(); i++){
            if(nums[i-1] > nums[i]) break;
        }
        if(i >= nums.size()) return;
        
        reverse(nums.begin(), nums.begin()+i);
        reverse(nums.begin()+i, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


