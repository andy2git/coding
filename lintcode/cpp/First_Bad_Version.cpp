/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int l = 1;
        int h = n;
        
        while(l <= h){
            if(l == h) return l;
            int m = l + (h-l)/2;
            
            if(VersionControl::isBadVersion(m)) h = m;
            else l = m+1;
        }
        
    }
};



