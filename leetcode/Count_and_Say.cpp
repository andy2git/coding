class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) throw runtime_error("invalid input!");
        
        string st = "1";
        while(n > 1){
            stringstream ss;
            int cnt = 1;
            for(int i = 1; i < st.size(); i++){
                if(st[i-1] == st[i]){
                    cnt++;
                }else{
                    ss << cnt << st[i-1];
                    cnt = 1;
                }
            }
            
            // last part of elements
            ss << cnt << st[st.size()-1];
            st = ss.str();
            n--;
        }
        
        return st;
    }
};
