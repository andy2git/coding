class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size() == 1) return num[0];
        
        int l = 0;
        int h = num.size() -1;
        while(l < h){
            if(l+1 == h) return min(num[l], num[h]);
            
            int m = l + (h-l)/2;
            if(num[m] < num[h]) h = m;
            // not sure which subarray to discard
            // can only remove one elem for next iteration
            else if (num[m] == num[h]) h--;
            else l = m;
        }
    }
};
