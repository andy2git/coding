class Solution {
public:
    string intToRoman(int num) {
        if(num <= 0) return "";
        
        vector<int> n_map = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s_map = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int i = 0;
        string result;
        while(num > 0){
            if(num - n_map[i] >= 0){
                num -= n_map[i];
                result += s_map[i];
            }else{
                i++;
            }
        }
        
        return result;
    }
};
