/**
 * ----------------------
 * ^[      two sum      ] 
 *  ^[                  ]
 *  time complexity O(n^2)
 */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size() < 3) return {};

        sort(num.begin(), num.end());

        int j, k;
        int sum;
        vector<vector<int>> result;
        for(int i = 0; i < num.size()-2; i++){
            // index i is used to filter out the duplicate case
            // Why if is safe to skip i if they are idential to previous elem?
            //      1. if solution contains i+1, then no need to include i+1
            //      2. if solution does not contain i+1, it will generate duplicated solutions if using i+1 
            if(i > 0 && num[i] == num[i-1]) continue;
            
            j = i+1;
            k = num.size()-1;
            
            while(j < k){
                sum = num[i] + num[j] + num[k];
                if(sum == 0){
                    result.push_back({num[i], num[j], num[k]});
                    while(num[j+1] == num[j]) j++;
                    while(num[k-1] == num[k]) k--;
                    j++;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return result;
    }
};
