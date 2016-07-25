public class Solution {
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    public boolean exist(char[][] board, String word) {
        if (word.isEmpty()) return true;
        if (board.length == 0) return false;

        int m = board.length;
        int n = board[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (existHelper(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean existHelper(char[][] board, int i, int j, String word, int k) {
        if (k == word.length()) {
            return true;
        }
        int m = board.length;
        int n = board[0].length;

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }

        if (board[i][j] == word.charAt(k)) {
            char t = board[i][j];
            board[i][j] = '*';
            if (existHelper(board, i + 1, j, word, k + 1)
                    || existHelper(board, i - 1, j, word, k + 1)
                    || existHelper(board, i, j + 1, word, k + 1)
                    || existHelper(board, i, j - 1, word, k + 1)) {
                return true;
            }
            board[i][j] = t;
        }
        return false;
    }
}
