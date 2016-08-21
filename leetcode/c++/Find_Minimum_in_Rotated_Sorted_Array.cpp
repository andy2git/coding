#include "leetcode.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) throw runtime_error("empty vector!");
        if(num.size() == 1) return num[0];
        
        size_t l = 0;
        size_t h = num.size()-1;
        size_t m;

        while(l < h){
            // always reduce to two elements, since num[m] is always included.
            if(l+1 == h) return min(num[l], num[h]);
            m = l + (h-l)/2;

            // if the array is sorted  [1, 2, 3, 4, 5]
            // for sorted array, we can check (num[l] < num[h]) directly
            //    - if(num[l] < num[m]) l = m; does not work for sorted array
            if(num[m] < num[h]) h = m;
            else l = m;
        }

        throw runtime_error("should not happen!"); 
    }
};


int main(){
    Solution sol;

    {   
        vector<int> vec = {1, 2, 3};
        cout << sol.findMin(vec) << endl;
    }

    {   
        vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
        cout << sol.findMin(vec) << endl;
    }

    {   
        vector<int> vec;
        cout << sol.findMin(vec) << endl;
    }
}
