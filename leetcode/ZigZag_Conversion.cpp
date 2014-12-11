/* very ugly solution */
class Solution {
public:
    string convert(string s, int nRows) {
        if(s.length() <= 1 || nRows == 1) return s;
        
        int step = 2*nRows-2;
        string result;
        
        for(int i = 0; i < nRows; i++){
            int stride = step - i*2;
            if(stride == 0) stride = step;

            bool flag = true;
            for(int j = i; j < s.length(); j += stride){
                if(!flag){
                    stride = step - stride;
                    if(stride == 0) stride = step;
                }
                flag = false;
                result += s[j];
            }
        }
        
        return result;
    }
};

