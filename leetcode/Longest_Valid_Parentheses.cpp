/**
 * dp solution 
 * t[i] : denote the length of the longest parenthesis including s[i]
 * ----------(     )((-----------))----
 *                  j             i
 * this j could concat two valid groups
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "") return 0;
        int n = s.size();
        
        vector<int> t(n, 0);
        int maxLen = 0;
        
        for(int i = 1; i < n; i++){
            if(s[i] == '(') t[i] = 0;
            else{
                int j = i-t[i-1]-1;
                if(j >= 0 && s[j] == '('){
                    t[i] += t[i-1]+2;
                    if(j-1 >= 0) t[i] += t[j-1];
                }
                if(t[i] > maxLen) maxLen = t[i];
            }
        }
        
        return maxLen;
    }
};

/**
 * stack solution
 * parenthesis matching, and see what is the longest match you can achieve
 */
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
