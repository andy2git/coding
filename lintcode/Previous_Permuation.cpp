class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        if(nums.size() <= 1) return nums;
        
        auto it = findBreakPoint(nums.begin(), nums.end());
        reverse(it, nums.end());
        
        //round it 
        if(it == nums.begin()) return nums;
        
        auto lt = it-1;
        auto up = upper_bound(it, nums.end(), *lt, greater<int>());
        iter_swap(lt, up);
        
        return nums;
    }
private:
    vector<int>::iterator findBreakPoint(vector<int>::iterator is, vector<int>::iterator ie){
        auto it = ie -1;
        while(it != is){
            if(*it >= *(it-1)) --it;
            else break;
        }
        
        return it;
    }
};
