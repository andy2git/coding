/**
 * C++ binary search functions:
 * upper_bound(is, ie, x) -> first element > x
 * lower_bound(is, ie, x) -> first element >= x 
 * 
 */
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        if(nums.size() <= 1) return nums;
        
        auto it = findBreakPoint(nums.begin(), nums.end()-1);
        reverse(it, nums.end());
        
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
