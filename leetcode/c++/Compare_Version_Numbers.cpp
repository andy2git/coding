class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0;
        int j = 0;
        while(i < v1.size() || j < v2.size()){
            int a = extractVersion(v1, i);
            int b = extractVersion(v2, j);
            
            if(a > b) return 1;
            else if(a < b) return -1;
        }
        
        return 0;
    }
private:
    int extractVersion(string &v, int &i){
        int result = 0;
        for(; i < v.size(); i++){
            if(v[i] == '.') break;
            result = result*10 + v[i] - '0';
        }
        i++;
        
        return result;
    }
};
