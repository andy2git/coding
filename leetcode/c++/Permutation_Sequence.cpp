class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> elems;
        for(int i = 1; i <= n; i++){
            elems.push_back(i);
        }
        
        return perm_helper(elems, k);
    }
private:
    int fac(int i){
        if(i == 1) return 1;
        int result = 1;
        while(i > 1){
            result *= i;
            i--;
        }
        return result;
    }
    
    string perm_helper(vector<int> &A, int k){
        string result;
        
        if(k == 1){
            for(int i = 0; i < A.size(); i++){
                result += (char)(A[i] + '0');
            }
            return result;
        }
        
        int range = fac(A.size()-1);
        int ind = (k-1)/range;
        
        int new_rank = k%range;
        if(new_rank == 0) new_rank += range;
        
        result += (char)(A[ind]+'0');
        A.erase(A.begin()+ind);
        
        result += perm_helper(A, new_rank);
        return result;
    }
};
