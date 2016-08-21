class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        int n = s.size();
        
        int i = 0;
        int j = n-1;
        reverseStr(s, i, j);
        
        int k = 0;
        int p = 0;
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] != ' ') s[k++] = s[i++];
            
            // at least a word with more than one char
            if(k > p){
                reverseStr(s, p, k-1);
                s[k++] = ' ';
                p = k;
            }
        }
        // remove the last ' '
        if(k > 0) s.resize(k-1);
        else s.resize(0);
    }

private:
    void reverseStr(string &s, int i, int j){
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};
