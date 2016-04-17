class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        if(nums.empty()) throw runtime_error("wrong input!");
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int k = (n+1)/2;
        return kthElem(nums, k, 0, n-1);
    }
private:
    int kthElem(vector<int> &A, int k, int s, int e){
        if(s > e) throw runtime_error("wrong range!");
        
        int p = partition(A, s, e);
        int q = p-s+1;
        
        if(q == k) return A[p];
        else if(q < k) return kthElem(A, k-q, p+1, e);
        else return kthElem(A, k, s, p-1);
    }
    
    int partition(vector<int> &A, int s, int e){
        int i = s;
        int j = e;
        
        int x = A[s];
        while(i <= j){
            if(A[i] <= x) i++;
            else{
                swap(A[i], A[j--]);
            }
        }
        swap(A[s], A[j]);
        
        return j;
    }
};

