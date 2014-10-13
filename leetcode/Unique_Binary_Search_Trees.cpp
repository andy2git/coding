#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += numTrees(i)*numTrees(n-i-1);
        }
        
        return sum;
    }
};


// memorize the temp result for faster recursion
class Solution_2 {
    
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        vector<int> A(n+1, 0);
        A[0] = A[1] = 1;
        
        return num_tree_helper(n, A);
    }
private:
    int num_tree_helper(int n, vector<int> &A){
        int cnt = 0;
        
        for(int i = 1; i <=n; i++){
            if(A[i-1] == 0){
                A[i-1] = num_tree_helper(i-1, A);
            }
            if(A[n-i] == 0){
                A[n-i] = num_tree_helper(n-i, A);
            }
            cnt += A[i-1]*A[n-i] ;
        }
        
        return cnt;
        
    }
};

class Solution_3 {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        vector<int> T(n+1, -1);
        
        numTrees_helper(T, n);
        
        return T[n];
    }
    
    int numTrees_helper(vector<int> &T, int n){
        if(n <= 1) return 1;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(T[i] == -1) T[i] = numTrees_helper(T, i);
            if(T[n-i-1] == -1) T[n-i-1] = numTrees_helper(T, n-i-1);
            sum += T[i]*T[n-i-1];
        }
        
        T[n] = sum;
        return T[n];
    }
};

// best solution with memoization
class Solution_4 {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        vector<int> T(n+1, 1);
        
        for(int i = 2; i < T.size(); i++){
            int sum = 0;
            for(int j = 0; j < i; j++){
                sum += T[j]*T[i-j-1];
            }
            T[i] = sum;
        }        
        
        return T[n];
    }
};

int main(){
    
    Solution sol;
    cout << sol.numTrees(50) << endl;

}
