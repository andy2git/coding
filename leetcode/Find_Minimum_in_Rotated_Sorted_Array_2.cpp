class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) throw runtime_error("empty vector!");
        if(num.size() == 1) return num[0];
        
        size_t l = 0;
        size_t h = num.size()-1;
        size_t m;
        
        while(l < h){
            if(l+1 == h) return min(num[l], num[h]);
            
            m = l + (h-l)/2;
            if(num[m] < num[h]){
                h = m;  

            // TODO: needs to be improved
            } else if(num[l] == num[m]){
                while(l < m && num[l] == num[m]) l++;
            } else if(num[h] == num[m]){
                while(h > m && num[h] == num[m]) h--;
            }else{
                l = m;
            }
        }
        
        if(l == h) return num[l];
    }
};
