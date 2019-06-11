class Solution {
    public List<String> commonChars(String[] A) {
        if(A == null || A.length == 0) return Collections.emptyList();

        int n = A.length;
        int size = 26;
        int[][] k = new int[n][size];

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < A[i].length(); j++) {
                k[i][A[i].charAt(j)-'a']++;
            }
        }

        List<String> result = new ArrayList<>();
        for(int j = 0; j < size; j++){
            int min = k[0][j];
            for(int i = 1; i < n; i++) min = Math.min(min, k[i][j]);
            while (min > 0) {
                result.add(String.valueOf((char)('a' + j)));
                min--;
            }
        }
        return result;
    }
}

// Another approach: we can use merge sorted array strategy. How to advance the pointers?


