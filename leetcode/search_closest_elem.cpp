// An iterative approach to find the closest element
int closest_search(vector<int> &A, int target){
    if(A.size() < 1) return -1;
   
    int l = 0;
    int h = A.size()-1;
    int m;
   
    int dis = INT_MAX;
    int min = -1;
    int t;
   
    while(l <= h){
        m = l + (h-l)/2;
       
        if(target == A[m]) return m;
        else if (target > A[m]) l = m + 1;
        else h = m-1;

        t = abs(target-A[m]);
        if( t < dis){
            dis = t;
            min = m;
        }
    }
    return min;
}

// An recursive version of find the closest element
int closest_search_recursive(vector<int> &A, int l, int h, int target){
    if(l > h) return -1;
   
    int m = l + (h-l)/2;
    int t;

    if(A[m] == target){
        return m;
    }else if(A[m] < target){
        t = closest_search_recursive(A, m+1, h, target);
    }else {
        t = closest_search_recursive(A, l, m-1, target);
    }

    if(t == -1){
        return m;
    }else{
        if(abs(A[t]-target) < abs(A[m]-target)) return t;
        else return m;
    }
}

