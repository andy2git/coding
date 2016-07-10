public class Solution {
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    public int findMin(int[] num) {
        if(num.length <= 0) throw new IllegalArgumentException("xxx");
        int l = 0;
        int h = num.length-1;
        
        while(l <= h){
            if(l == h) return num[l];
            
            int m = l + (h-l)/2;
            if(num[m] < num[h]) h = m;
            else if(num[m] == num[h]) h--;
            else l = m+1;
        }
        
        throw new RuntimeException("should not be here!");
    }
}

