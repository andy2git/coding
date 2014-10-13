#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct to_lower{
    char operator()(const char ch){
        if(ch <= 'Z' && ch > 'A'){
            return ch -'A'+'a';
        }
        return ch;
    }

};

const int SIZE = 256;
bool is_pangram(string &st){
    vector<bool> marker(SIZE, false);
    //transform(st.begin(), st.end(), st.begin(), ::tolower);
    transform(st.begin(), st.end(), st.begin(), to_lower());
    
    for(int i = 0; i < st.size(); i++){
        marker[st[i]] = true;
    }
    
    for(char i = 'a'; i <= 'z'; i++){
        if(marker[i] == false) return false;
    }
    
    return true;
}


int main(){
    string st = "The quick brown fox jumps over the lazy dog.";
    cout << "is_pangram:" << is_pangram(st) << endl;
}
