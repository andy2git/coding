/**
 * Problem:
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
 *
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return {};
        
        vector<string> result;
        restoreIpHelper(result, "", s, 0, 0);
        return result;
    }
    
private:
    void restoreIpHelper(vector<string> &result, string sofar, string &remain, int k, int m){
        if(k == 4 && m == remain.size()){
            result.push_back(sofar);
            return;
        }else if(k == 4 && m < remain.size()){
            return;
        }else if(m == remain.size() && k < 4) return;
        
        int n = remain.size();
        for(int i = m; i < min(m+3, n); i++){
            string st = remain.substr(m, i-m+1);
            if(i > m && remain[m] == '0') break;
            
            int t = stoi(st);
            if(t <= 255){
                if(k == 3) restoreIpHelper(result, sofar+st, remain, k+1, i+1);
                else restoreIpHelper(result, sofar+st+".", remain, k+1, i+1);
            }
        }
    }
};
