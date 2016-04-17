#include <sstream>

bool num_cmp(int a, int b){
    stringstream ss;
    ss << a;
    ss << b;
    
    stringstream ss2;
    ss2 << b;
    ss2 << a;
    
    return ss.str() > ss2.str();
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        sort(num.begin(), num.end(), num_cmp);
        
        string st;
        for(int i =0; i < num.size(); i++){
            if(st.size() > 0 && st[0] == '0') st = "";
            st += to_string(num[i]);
        }
        
        return st;
    }
};
