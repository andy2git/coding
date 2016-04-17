class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int n = nums.size();
        return kth(nums, 0, n-1, k);
        
    }
private:
    int kth(vector<int> &nums, int s, int e, int k){
        if(s > e) return -1;
        
        int p = partition(nums, s, e);
        int q = p-s+1;
        
        if(q == k) return nums[p];
        else if (k < q) return kth(nums, s, p-1, k);
        else return kth(nums, p+1, e, k-q);
    }
    
    int partition(vector<int> &nums, int s, int e){
        if(s == e) return s;
        
        int x = nums[s];
        int i = s;
        int j = e;
        while(i <= j){
            if(nums[i] >= x) i++;
            else swap(nums[i], nums[j--]);
        }
        swap(nums[s], nums[j]);
        return j;
    }
};
