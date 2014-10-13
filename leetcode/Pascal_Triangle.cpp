class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows <= 0) return vector<vector<int>>();

        vector<vector<int>> result = {{1}};
        vector<int> layer;
        int k = 2;
        int t;
        
        while(k <= numRows){
            layer.clear();
            for(int i = 0; i < k; i++){
                
                if(i > 0) t = result[k-2][i-1];
                else t = 0;
                
                if(i < k-1) t += result[k-2][i];
                else t += 0;
                layer.push_back(t);
            }
            result.push_back(layer);
            k++;
        }
        
        return result;
    }
};
