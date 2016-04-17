class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        vector<int> m(26, 0);
        
        for(auto c : A){
            m[c-'A']++;
        }
        
        for(auto c : B){
            int k = c-'A';
            m[k]--;
            if(m[k] < 0) return false;
        }
        
        return true;
    }
};



