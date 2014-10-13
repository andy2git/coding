class Solution {
public:
    string countAndSay(int n) {
        string st = "1";
        if(n == 1) return st;
        
        stringstream ss; 
        while(n > 1){
            int cnt = 1;
            ss.str("");
            ss.clear();
            for(int i = 1; i < st.size(); i++){
                if(st[i] == st[i-1]){
                    cnt++;
                }else{
                    ss << cnt << st[i-1];
                    cnt = 1;
                }
            }
            ss << cnt << st[(int)st.size()-1];
            st = ss.str();
            
            n--;
        }
        
        return st;
    }
};
