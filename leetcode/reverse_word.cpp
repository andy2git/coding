class Solution {
public:
    void reverseWords(string &s) {
        if(s == "") return;
        
        reverse_str(s, 0, s.size()-1);
        
        int i = 0;
        int j = 0;
        int n = s.size();
        int k = 0;
        
        while(j < n){
            while(j < n && s[j] == ' ') j++;
            
            k = i;
            while(j < n && s[j] != ' '){
                s[i++] = s[j++];
            }
            if(i > k) s[i++] = ' ';
            
            reverse_str(s, k, i-2);
        }
        
        if(i > 0) s.resize(i-1);
        else s.resize(0);
    }
private:
    // index [s, e]
    void reverse_str(string &st, int s, int e){
        if(s > e) return;
        
        while(s < e){
            swap(st[s], st[e]);
            s++;
            e--;
        }
    }
};
