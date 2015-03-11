/**
 * http://leetcode.com/2010/04/finding-prime-numbers.html
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findPrimeNums(int n){
    vector<bool> m(n+1, true);
    m[0] = m[1] = false;
    
    // do not forget the i<=limit and j<=n here
    int limit = sqrt(n);
    for(int i = 2; i <= limit; i++){
        if(m[i]){
            for(int j = i*i; j <= n; j+=i){
                m[j] = false;
            }
        }
    }
    
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(m[i]) result.push_back(i);
    }
    
    return result;
}

int main(){
    vector<int> A = findPrimeNums(100);
    for_each(A.begin(), A.end(), [](int x){cout << x << "\t";});
    cout << endl;
}
