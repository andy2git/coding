class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        int l, h;
        l = h = num[0];
        
        for(int i = 1; i < num.size(); i++){
            if(num[i] > h) h = num[i];
            if(num[i] < l) l = num[i];
        }
        
        int n = num.size();
        vector<int> lower(n, -1);
        vector<int> upper(n, -1);
        
        for(int i = 0; i < num.size(); i++){
            int k = (int)floor(((float)(num[i]-l))*(n-1)/(h-l));
            if(lower[k] == -1){
                lower[k] = upper[k] = num[i];
            }else{
                if(num[i] > upper[k]) upper[k] = num[i];
                if(num[i] < lower[k]) lower[k] = num[i];
            }
        }
        
        int maxDis = upper[0] - lower[0];
        int pre = upper[0];
        for(int i = 1; i < n; i++){
            if(lower[i] == -1) continue;
            
            int dis = lower[i] - pre;
            pre = upper[i];
            if(dis > maxDis) maxDis = dis;
        }
        
        return maxDis;
    }
};
