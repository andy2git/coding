#include <string>
#include <vector>
using namespace std;

string longest_common_substr(string &s, string &t){

    if(s.empty() || t.empty()) return "";
    
    int m = s.length();
    int n = t.length();
    int x = -1;
    int maxLen  = -1;
    vector<vector<int>> tbl(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            if(i == 0 || j == 0) tbl[i][j] = (s[i] == t[j])? 1 : 0;
            if(i > 0 && j > 0){
                if(s[i] == t[j]) tbl[i][j] = tbl[i-1][j-1] + 1;
                else tbl[i][j] = 0;
            }
            
            if(tbl[i][j] > maxLen){
                maxLen = tbl[i][j];
                x = i;
            }
        }
    }
    
    return s.substr(x-maxLen+1, maxLen);
    
}

int main(){
    string s = "OldSite:GeeksforGeeks.org";
    string t = "NewSite:GeeksQuiz.com";
    cout << longest_common_substr(s, t) << endl;
}
