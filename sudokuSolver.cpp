class Solution {
public:

  bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, i, j, c)) {
              board[i][j] = c;

              if (solve(board)) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>>& board, int i, int j, char c) {
    for (int k = 0; k < 9; k++) {
      if (board[i][k] == c || board[k][j] == c) {
        return false;
      }
      if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c) {
        return false;
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>>& board) {
    solve(board);
  }
};