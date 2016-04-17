/* similar to the majority vote solution */
/**
 * Solution: every char cross will eliminate 3 different elements. 
 * So an element which occurs more than n/3 times will definitely 
 * be left.
 * 
 */
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        if(nums.size() <= 2) throw runtime_error("wrong input!");
        
        int a, b;
        int cntA = 0, cntB = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(cntA > 0 && nums[i] == a){
                cntA++;
            } else if(cntB > 0 && nums[i] == b){
                cntB++;
            } else if(cntA == 0) {
                a = nums[i];
                cntA++;
            }else if (cntB == 0){
                b = nums[i];
                cntB++;
            }else{
              cntA--;
              cntB--;
            }
        }
        
        // have to check at the end to decide who is the one.
        cntA = 0;
        cntB = 0;
        for(int x: nums){
            if(x == a) cntA++;
            if(x == b) cntB++;
        }
        
        if(cntA > cntB) return a;
        else return b;
    }
};

/* partation based solution */
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n = nums.size();

        int k = n/3 +1;
        int a = orderStat(nums, 0, n-1, k);

        k = n - n/3;
        int b = orderStat(nums, 0, n-1, k);
        
        if(isValid(nums, a)) return a;
        else return b;
    }
    
private:
    bool isValid(vector<int> &nums, int a){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == a) cnt++;
        }
        return cnt > nums.size()/3;
    }
    
    int orderStat(vector<int> &nums, int s, int e, int k){
        if(s > e) return -1;
        
        int p = partition(nums, s, e);
        int q = p-s+1;
        if(q == k) return nums[p];
        else if(q < k) return orderStat(nums, p+1, e, k-q);
        else return orderStat(nums, s, p-1, k);
    }
    
    int partition(vector<int> &nums, int s, int e){
        if(s > e) return -1;
        
        int x = nums[s];
        int i = s;
        int j = e;
        
        while(i <= j){
            if(nums[i] <= x) i++;
            else swap(nums[i], nums[j--]);
        }
        swap(nums[s], nums[j]);
        return j;
    }
};
