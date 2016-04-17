class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        if(s == "") return s;
        
        int n = s.size();
        revStr(s, 0, n-1);
        
        // reverse word by word
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            
            if(j > k){
                revStr(s, k, j-1);
                s[j++] = ' ';
            }
            k = j;
        }
        
        return s.substr(0, j);
    }
private:
    void revStr(string &s, int i, int j){
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};
