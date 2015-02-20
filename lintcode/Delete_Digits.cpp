class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        if(k <= 0) return A;
        while(k > 0){
            delOneDigit(A);
            k--;
        }
        
        // remove front 0s
        int i = 0;
        for(; i < A.size(); i++){
            if(A[i] != '0') break;
        }
        
        return A.substr(i);
    }
    
private:
    void delOneDigit(string &A){
        bool flag = false;
        
        for(int i = 0; i < A.size()-1; i++){
            if(flag){
                A[i] = A[i+1];
            }else{
                if(A[i] > A[i+1]){
                    A[i] = A[i+1];
                    flag = true;
                }
            }
        }
        
        A.resize(A.size()-1);
    }
};
