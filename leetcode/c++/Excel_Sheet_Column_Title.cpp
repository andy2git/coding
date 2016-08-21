class Solution {
private:
    const int N = 26;
public:
    string convertToTitle(int n) {
        if(n <= 0) throw runtime_error("n < 0");
        // init M
        char M[N];
        for(int i = 0; i < N; i++) M[i] = i+'A';

        string st;        

        while(n){
            st = M[(n-1)%N] + st;
            n = (n-1)/N;
        }
        
        return st;
    }
};
