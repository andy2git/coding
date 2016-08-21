class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> h(m, vector<int>(n, 0));
        
        computeMaxHeightPerCol(matrix, h);
        
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            int area = largestRectangleArea(h[i]);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }

private:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()) return 0;
        
        int i = 0;
        int n = height.size();
        
        stack<int> st;
        int maxArea = INT_MIN;
        while(i < n){
            if(st.empty()) st.push(i++);
            else if(height[st.top()] <= height[i]) st.push(i++);
            else{
                int x = st.top();
                st.pop();
                
                int left = st.empty()? -1 : st.top();
                int area = height[x]*(i-left-1);
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()){
            int x = st.top();
            st.pop();
            
            int left = st.empty()? -1 : st.top();
            int area = height[x]*(i-left-1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
    
    void computeMaxHeightPerCol(vector<vector<char>> &matrix, vector<vector<int>> &h){
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(matrix[i][j] == '0') h[i][j] = 0;
                else h[i][j] += (i==0)? 1:h[i-1][j]+1;
            }
        }
    }
};
