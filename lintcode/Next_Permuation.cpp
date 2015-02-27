/**
 * C++ binary search functions:
 * upper_bound(is, ie, x) -> first element > x
 * lower_bound(is, ie, x) -> first element >= x 
 * 
 */
/* Implementation#1: using C index */
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        if(nums.size() <= 1) return nums;
        
        int ind = findBreakPoint(nums);
        sort(nums.begin()+ind, nums.end());
        
        if(ind == 0) return nums;
        
        int i = ind - 1;
        auto it  = upper_bound(nums.begin()+ind, nums.end(), nums[i]);
        int j = it - nums.begin();
        swap(nums[i], nums[j]);
        return nums;
    }
private:
    int findBreakPoint(vector<int> &nums){
        int n = nums.size();
        int i = n-1;
        
        while(i > 0){
            if(nums[i] <= nums[i-1]) i--;
            else break;
        }
        
        return i;
    }
};

/* Implementation#2: using C++ iterator */
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        if(nums.size() <= 1) return nums;
        
        auto it = findBreakPoint(nums.begin(), nums.end()-1);
        sort(it, nums.end());
        
        // round it up
        if(it == nums.begin()) return nums;
        
        // next permutation
        auto lt = it-1;
        auto up  = upper_bound(it, nums.end(), *lt);
        iter_swap(lt, up);
        
        return nums;
    }
private:
    // [is, ie]
    vector<int>::iterator findBreakPoint(vector<int>::iterator is, vector<int>::iterator ie){
        auto it = ie;
        
        while(it != is){
            if(*it <= *(it-1)) --it;
            else break;
        }
        
        return it;
    }
};
