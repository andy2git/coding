class Solution {
public:
    void reverseWords(string &s) {
        if(s.length() < 1) return;
        size_t n = s.length();
        
        //reverse the whole string
        reverse_str(s, 0, n-1);
        int i = 0;
        int k = 0;
        int m = 0;
        
        while(i < n){
            //reverse word by word
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] != ' ') s[k++] = s[i++];
        
            if(k > m) {
                reverse_str(s, m, k-1);
                s[k++] = ' ';
                m = k;
            }
        }
        
        if(k > 0) s.resize(k-1);
        else s.resize(0);
    }
private:
    void reverse_str(string &s, int b, int e){
        while(b < e){
            swap(s[b++], s[e--]);
        }
    }

};
