class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int l = 0;
        int h = num.size()-1;
        
        while(l <= h){
            if(l == h) return num[l];
            
            int m = l + (h-l)/2;
            if(num[m] < num[h]) h = m;
            else if(num[m] == num[h]) h--;
            else l = m+1;
        }
        
        throw runtime_error("should not be here!");
    }
};
