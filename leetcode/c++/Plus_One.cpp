class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int cbit = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            digits[i] = addDigit(digits[i], cbit);
        }
        
        if(cbit == 1) digits.insert(digits.begin(), 1);
        
        return digits;
    }
private:
    int addDigit(int x, int &cbit){
        int t = x+cbit;
        cbit = 0;
        
        if(t >= 10){
            cbit = 1;
            t %= 10;
        }
        return t;
    }
};
