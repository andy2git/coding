class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.empty()) return 0;
        
        int l = 1;
        vector<int>::iterator it = max_element(L.begin(), L.end());
        int h = *it;
        int m;
        int len = 0;
        
        while(l <= h){
            m = l + (h-l)/2;
            int w = numofEqualWoods(L, m);
            if(w >= k){
                len = m;
                l = m+1;
            }else h = m-1;
        }
        
        return len;
    }
private:
    int numofEqualWoods(vector<int> &L, int m){
        int result = 0;
        
        for(int i = 0; i < L.size(); i++){
            result += L[i]/m;
        }
        
        return result;
    }
};


