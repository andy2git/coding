/* recursive solution */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(rowIndex == 0) return vector<int>(1, 1);
        
        vector<int> p_row = getRow(rowIndex-1);
        vector<int> c_row;
        
        c_row.push_back(1);
        for(int i = 1; i < p_row.size(); i++){
            c_row.push_back(p_row[i] + p_row[i-1]);
        }
        c_row.push_back(1);
        
        return c_row;
    }
};

/* iterative solution */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) return vector<int>();
        vector<int> layer = {1};
        vector<int> next_layer;
        
        int k = 1;
        int t;
        while(k <= rowIndex){
            for(int i = 0; i <= k; i++){
                
                if(i > 0) t = layer[i-1];
                else t = 0;
                
                if(i < k) t += layer[i];
                else t += 0;
                next_layer.push_back(t);
            }
            layer = next_layer;
            next_layer.clear();
            k++;
        }
        
        return layer;
    }
};
