class Solution {
public:
    void nextPermutation(vector<int> &num) {
        
        int k = find_break(num);
        
        if(k == -1){
            sort(num.begin(), num.end());
        }else{
            sort(num.begin()+k+1, num.end());
            
            for(int i = k+1; i < num.size(); i++){
                if(num[i] > num[k]){
                    swap(num[k], num[i]);
                    break;
                }
            }
        }
    }

private:
    int find_break(vector<int> &A){
        if(A.size() < 2) return -1;
        
        for(int i = A.size()-1; i>0; i--){
            if(A[i] > A[i-1]) return i-1;
        }
        
        return -1;
    }
};
