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
        vector<string> result;
        
        restore_ip_helper(result, "", s, 0);
        
        return result;
    }
private:
    void restore_ip_helper(vector<string> &result, string sofar, string remain, int k){
        if(k == 3){
            if(!remain.empty() && (remain[0] == '0'||  stol(remain) > 255)) return;
            else {
                result.push_back(sofar.substr(1) + '.' + remain);
                return;
            }
        }
        
        int len = std::min(3, (int)remain.length());
        for(int i = 0; i < len; i++){
            if(remain[0] == '0') break;
            string t = remain.substr(0, i+1);
            if(stoi(t) <= 255){
                restore_ip_helper(result, sofar + "." + t, remain.substr(i+1), k+1);
            }else break;
        }
    }
};
