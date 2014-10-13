class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.empty()) return 0;
        
        int i = 0;
        int j = (int)height.size()-1;
        int max_area = min(height[i], height[j])*(j-i);
        
        while(i < j){
            if(height[i] < height[j]){
                i = next_forward(height, i);
                if(i < 0) break;
            }else{
                j = next_backward(height, j);
                if(j < 0) break;
            }
            
            int t = min(height[i], height[j])*(j-i);
            if(t > max_area){
                max_area = t;
            }
        }
        
        return max_area;
    }
    
private:
    // (s, ---)
    int next_forward(vector<int> &A, int s){
        for(int i = s+1; i < A.size(); i++){
            if(A[i] > A[s]) return i;
        }
        
        return -1;
    }
    
    int next_backward(vector<int> &A, int e){
        for(int i = e-1; i >= 0; i--){
            if(A[i] > A[e]) return i;
        }
        
        return -1;
    }
    
};
