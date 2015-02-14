class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> result;
        
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxCnt = 0;
        int minCnt = 0;
        
        maxHeap.push(nums[0]);
        maxCnt = 1;
        result.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];
            if(x <= maxHeap.top()) {
                maxHeap.push(x);
                maxCnt++;
            }else{
                minHeap.push(x);
                minCnt++;
            }
            
            while(maxCnt - minCnt >= 2){
                int t = maxHeap.top();
                maxHeap.pop();
                minHeap.push(t);
                maxCnt--;
                minCnt++;
            }
            
            while(minCnt - maxCnt >= 2){
                int t = minHeap.top();
                minHeap.pop();
                maxHeap.push(t);
                maxCnt++;
                minCnt--;
            }
            
            if(maxCnt >= minCnt) result.push_back(maxHeap.top());
            else result.push_back(minHeap.top());
        }
        
        return result;
        
    }
};
