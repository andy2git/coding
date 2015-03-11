/* using stack O(n) */
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
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
};

/** brute force solution O(n^2) */
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()) return 0;
        
        int n = height.size();
        int maxRegion = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int m = height[i];
            for(int j = i; j < n; j++){
                m = min(m, height[j]);
                maxRegion = max(maxRegion, (j-i+1)*m);
            }
        }
        
        return maxRegion;
    }
};

/* Divide and conquer O(nlgn) expected run time */
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        if(height.empty()) return 0;
        
        return largestRectangleHelper(height.begin(), height.end());
    }
private:
    // [is, ie)
    int largestRectangleHelper(vector<int>::iterator is, vector<int>::iterator ie){
        if(is == ie) return 0;
        
        auto it = min_element(is, ie);
        int ml = largestRectangleHelper(is, it);
        int mr = largestRectangleHelper(it+1, ie);
        
        int area = (*it)*(ie-is);
        
        return max(max(ml, mr), area);
    }

};
