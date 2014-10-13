/* DP based on the recursive version */
class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 1) return true;
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        
        return can_jump_helper(A, n, 0, dp); 
    }
private:
    bool can_jump_helper(int A[], int n, int s, vector<int> &dp){
        if(s >= n-1) return true;
        
        bool result = false;
        for(int i = 1; i <= A[s]; i++){
            if(dp[s+i] == 1) return true;
            else if(dp[s+i] == 0){
            }else{
                result = can_jump_helper(A, n, s+i, dp);    
                dp[s+i] = result;
                if(result) return true;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 1) return true;
        vector<bool> dp(n, false);
        dp[0] = true;
        
        for(int i = 0; i < n; i++){
            if(dp[i]){
                for(int j = 1; j <= A[i]; j++){
                    if(i+j < n) dp[i+j] = true;
                    else return true;
                }
            }
        }
        
        return dp[n-1];
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        
        int m = 0;
        for(int i = 0; i < n; i++){
            if(i <= m){
                if(i+A[i] > m){
                    m = i+A[i];
                    if(m >= n-1) return true;
                }
            }
        }
        
        return false;
    }
};
