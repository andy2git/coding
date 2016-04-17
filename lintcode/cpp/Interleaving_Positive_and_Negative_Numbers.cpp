class Solution {
public:
    /**
     * @param A: An integer array.
     * @return an integer array
     */
    vector<int> rerange(vector<int> &A) {
        // write your code here
        if(A.size() <= 2) return A;
        
        int k = partition(A);
        int x = k;
        int y = A.size()-k;
        reverse(A, x, y);
        
        return A;
    }
private:
    int partition(vector<int> &A){
        int i = 0;
        int j = A.size()-1;
        while(i <= j){
            if(A[i] < 0) i++;
            else if(A[i] > 0) swap(A[i], A[j--]);
            else throw runtime_error("has 0 inside, wrong input!");
        }
        return i;
    }
    
    void reverse(vector<int> &A, int x, int y){
        int i = 0;
        int j = 0;
        
        if(x == y){
            i = 1;
            j = A.size()-2;
        }else if(x < y){
            i = 0;
            j = A.size()-2;
        }else{
            i = 1;
            j = A.size()-1;
        }
        
        while(i < j){
            swap(A[i], A[j]);
            i += 2;
            j -= 2;
        }
    }
};
