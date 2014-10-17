class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return -1;
        if(num.size() == 1) return num[0];
        
        int l = 0;
        int h = num.size()-1;
        int m;

        while(l < h){
            if(l+1 == h) return min(num[l], num[h]);
            m = l + (h-l)/2;
            if(num[m] < num[h]) h = m;
            else l = m;
        }
    }
};
