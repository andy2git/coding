class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int l = 0;
        int h = colors.size()-1;
        
        sortColorHelper(colors, l, h, 1, k);    
    }
    
private:
    void sortColorHelper(vector<int> &A, int s, int e, int l, int h){
        if(s >= e) return;
        
        int m = l+(h-l)/2;
        pair<int, int> k = partition(A, s, e, m);
        sortColorHelper(A, s, k.first-1, l, m-1);
        sortColorHelper(A, k.second+1, e, m+1, h);
    }
    
    pair<int, int> partition(vector<int> &A, int s, int e, int m){
        int i = s, k = s;
        int j = e;
        
        while(k <= j){
            if(A[k] == m) k++;
            else if(A[k] < m) swap(A[i++], A[k++]);
            else swap(A[k], A[j--]);
        }
        
        return make_pair(i, j);
    }
    
};


