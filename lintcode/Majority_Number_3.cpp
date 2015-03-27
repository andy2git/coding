class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        unordered_map<int, int> map;
        
        for(auto x: nums){
            if(map.size() < k-1){
                map[x]++;
            }else{
                if(map.find(x) == map.end()){
                    //cross out chars
                    for(auto it = map.begin(); it != map.end();){
                        --(it->second);
                        if(it->second == 0) it = map.erase(it);
                        else ++it;
                    }
                }else{
                    map[x]++;
                }
            }
        }

        
        for(auto it = map.begin(); it != map.end(); ++it){
            it->second = 0;
        }
        
        for(auto x : nums){
            if(map.find(x) != map.end()){
                map[x]++;
                if(map[x] > nums.size()/k) return x;
            }
        }
        return -1;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> cand(k, 0);
        
        for(int i = 1; i <= k; i++){
            int r = i*n/k;
            cand[i-1] = orderStat(nums, 0, n-1, r);
        }
        
        for(int x : cand){
            if(isValid(nums, x, k)) return x;
        }
    }

private:
    bool isValid(vector<int> &nums, int a, int k){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == a) cnt++;
        }
        return cnt > nums.size()/k;
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
