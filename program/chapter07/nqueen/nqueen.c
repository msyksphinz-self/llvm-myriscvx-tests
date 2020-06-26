// #include <stdio.h>
// #include <string.h>

#include "nqueen.h"

// void printBoard (int board[N][N])
// {
//   printf("------\n");
//   for (int y = 0; y < N; y++) {
//     for (int x = 0; x < N; x++) {
//       printf("%d ", board[y][x]);
//     }
//     printf("\n");
//   }
// }

void printQueen(int queen[N]);

void changeBoard(int board[N][N], int y, int x, int d)
{
  int k;

  for (k = 0; k < N; k++) {
    board[y][k] += d;             /* 横方向 */
    board[k][x] += d;             /* 縦方向 */
  }
  if (y > x) {
    for (k = 0; k < N-(y-x); k++) {
      board[k+(y-x)][k] += d;   /* 右下がり斜め方向 (i > jのとき） */
    }
  } else {
    for (k = 0; k < N-(x-y); k++) {
      board[k][k+(x-y)] += d;   /* 右下がり斜め方向 (i <= jのとき） */
    }
  }
  if (y+x < N) {
    for (k = 0; k <= x+y; k++) {
      board[y+x-k][k] += d;     /* 左下がり斜め方向（i +j < Nのとき） */
    }
  } else {
    for (k = y+x-N+1; k < N; k++) {
      board[y+x-k][k] += d;     /* 左下がり斜め方向（i+j >= Nのとき） */
    }
  }
}

void setQueen(int queen[N], int board[N][N], int y)
{

  for (int x = 0; x < N; x++) {
    if (board[y][x] == 0) {
      queen[y] = x + 1;
      if (y == N-1) {
        printQueen(queen);
      } else {
        changeBoard(board, y, x, +1);
        setQueen(queen, board, y+1);
        changeBoard(board, y, x, -1);
      }
    }
  }
}
