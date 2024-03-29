#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, pair<int, int>> pcii;
// Bruteforcing
// Need to check right-side and down-side
// 1. Switch two candies if they are different
// 2. Count the number of candies in two columns when you switch in right-side
// 3. Count the number of candies in two rows when you switch in down-side

char board[51][51];
// 0 - right, 1 - down
const int x_move[] = {1, 0};
const int y_move[] = {0, 1};
int N, max_cnt;

int countByRow() {
  int cnt_max = 1;
  for (int i = 0; i < N; i++) {
    // i indicate the index of row
    int cnt = 1;
    for (int j = 0; j < N; j++) {
      if (board[i][j] == board[i][j + 1]) {
        cnt++;
      } else {
        if (cnt > cnt_max) cnt_max = cnt;
        cnt = 1;
      }
    }
  }
  return cnt_max;
}

int countByColumn() {
  int cnt_max = 1;
  for (int i = 0; i < N; i++) {
    // i indicate the index of column
    int cnt = 1;
    for (int j = 0; j < N; j++) {
      if (board[j][i] == board[j + 1][i]) {
        cnt++;
      } else {
        if (cnt > cnt_max) cnt_max = cnt;
        cnt = 1;
      }
    }
  }
  return cnt_max;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> board[i][j];

  // Swap and Count row and column
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      int col, row;
      swap(board[i][j], board[i][j + 1]);
      col = countByColumn();
      row = countByRow();

      max_cnt = max(max_cnt, col);
      max_cnt = max(max_cnt, row);

      swap(board[i][j + 1], board[i][j]);
      swap(board[i][j], board[i + 1][j]);

      col = countByColumn();
      row = countByRow();
      max_cnt = max(max_cnt, col);
      max_cnt = max(max_cnt, row);

      swap(board[i + 1][j], board[i][j]);
    }
  }
  cout << max_cnt;
  return 0;
}