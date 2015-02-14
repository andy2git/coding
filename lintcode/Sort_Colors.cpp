class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 1) return;
        
        int i = 0; 
        int j = 0;
        int k = nums.size()-1;
        
        while(i <= k){
            if(nums[i] == 1) i++;
            else if(nums[i] < 1) swap(nums[i++], nums[j++]);
            else swap(nums[i], nums[k--]);
        }
        
        return;
    }
};


