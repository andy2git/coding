/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

/* Application: git bisect to find the commit which causes the issue*/

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        
        while(s < e) {
            int m = s + (e-s)/2;
            if(isBadVersion(m)) e = m;
            else s = m+1;
        }
        return s;
    }

}


/* Recursive solution */
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if(n <= 0) return n;
        return fbv_h(1, n);
    }
    
    private int fbv_h(int s, int e) {
        if (s > e) return -1;
        int k = s + (e-s)/2;
        if(!isBadVersion(k)) return fbv_h(k+1, e);
        else {
            int p = fbv_h(s, k-1);
            if(p == -1) return k;
            else return p;
        }
    }
}
