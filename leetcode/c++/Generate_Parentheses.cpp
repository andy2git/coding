/**
 * Solution: 
 *      l: #(    r: #)
 *  If #( is less than half, then you can keep adding (
 *  If l > r, then you can keep adding ) 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0) return {};
        if(n == 1) return {"()"};
        
        vector<string> result;
        string sofar;
        
        parenthesisHelper(result, sofar, 0, 0, 2*n);
        return result;
    }
private:
    void parenthesisHelper(vector<string> &result, string sofar, int l, int r, int m){
        if(l+r == m) {
            result.push_back(sofar);
            return;
        }
        
        if(l < m/2) parenthesisHelper(result, sofar+'(', l+1, r, m);
        if(l > r) parenthesisHelper(result, sofar+')', l, r+1, m);
    }
};
