class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "") return 0;
        
        int max_len = 0;
        int len = 0;
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    
                    if(st.empty()) len = i+1;
                    else len = i - st.top();
                    
                    if(len > max_len) max_len = len;
                }else{
                    st.push(i);
                }
            }
        }
        
        return max_len;
    }
};
