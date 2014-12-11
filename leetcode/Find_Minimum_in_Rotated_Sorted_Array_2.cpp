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
            else if (num[m] == num[h]) h--;
            else l = m;
        }
    }
};
