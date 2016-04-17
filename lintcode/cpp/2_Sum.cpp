class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if(m.find(x) != m.end()){
                return {m[x]+1, i+1};
            }else{
                m[nums[i]] = i;
            }
        }
        
        // no solution
        return {};
    }
};



