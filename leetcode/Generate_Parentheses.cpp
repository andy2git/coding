class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};
        
        vector<string> result;
        string sofar = "(";
        
        parenthesis_helper(result, sofar, 1, 1, 0, 2*n);
        return result;
    }
private:
    void parenthesis_helper(vector<string> &result, string sofar, int k, int l, int r, int m){
        if(k == m){
            result.push_back(sofar);
            return;
        }
        
        if(r > l) return;
        
        if(l < m/2) parenthesis_helper(result, sofar + "(", k+1, l+1, r, m);
        if(r < m/2) parenthesis_helper(result, sofar + ")", k+1, l, r+1, m);
    }
};
