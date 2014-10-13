class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int min = INT_MAX;
        int j, k;
        int t;
        int solution;
        
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size()-2; i++){
            j = i+1;
            k = num.size()-1;
            
            while(j < k){
                t = num[i]+num[j]+num[k];
                
                if(t == target) return t;
                else if(t < target){
                    int dis = abs(t-target);
                    if(dis < min){
                        min = dis;
                        solution = t;
                    }
                    j++;    
                }else{
                    int dis = abs(t-target);
                    if(dis < min){
                        min = dis;
                        solution = t;
                    }
                    k--;
                }
            }
        }
        
        return solution;
    }
};
