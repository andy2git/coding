class Solution {
    public int[] sortedSquares(int[] A) {
        if (A == null || A.length == 0) return A;
        int i = 0;
        int j = A.length - 1;
        int[] result = new int[A.length];
        int k = result.length-1;

        while (i <= j) {
            if (A[i] * A[i] <= A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            } else {
                result[k--] = A[i] * A[i];
                i++;
            }

        }

        return result;
    }
}

// Solution: how to solve this problem in place?
// --------------------><---------
// ALSO we have to pick up the bigger values first, so two indices
// will not cross each other after it reaches to its end
