// Question: Find a largest element which is less or equal to the target

// An iterative approach
int floor(vector<int> &A, int target){
    if(A.empty()) return -1;
   
    int l = 0;
    int h = A.size()-1;
    int m;
   
    int min = -1;
    int dis = INT_MAX;
    int t;
   
    while (l <= h){
        m = l + (h-l)/2;
       
        if(A[m] == target){
            return m;
        }else if (A[m] < target){
            t = target - A[m];
            if(t < dis){
                dis = t;
                min = m;
            }
            l = m+1;
        }else{
            h = m-1;
        }
    }
   
    return min;
}

// An recursive version
// [l, h]
int floor_recursive(vector<int> &A, int l, int h, int target){
    if(l > h) return -1;
   
    int m = l + (h-l)/2;
    if(A[m] == target) return m;
    else if(A[m] < target){
        int t = floor_recursive(A, m+1, h, target);
        if(t == -1) return m;
        else return t;
    }else return floor_recursive(A, l, m-1, target);
}
