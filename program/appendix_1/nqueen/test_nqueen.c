#include <stdio.h>
#include <string.h>
#include "nqueen.h"

extern void findSolution();

void setQueen(int queen[N], int board[N][N], int i);

void printQueen(int queen[N])
{
  printf("%d queen\n", N);
  for (int y = 0; y < N; y++) {
    printf("%d ", queen[y]);
  }
  printf("\n");

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      printf("---");
    }
    printf("-\n");
    for (int x = 0; x < N; x++) {
      if (x + 1 == queen[y]) {
        printf("|x ");
      } else {
        printf("|  ");
      }
    }
    printf("|\n");
  }
  for (int x = 0; x < N; x++) {
    printf("---");
  }
  printf("-\n");
}

int main()
{
  int queen[N];
  int board[N][N];

  memset(board, 0, sizeof(board));
  setQueen(queen, board, 0);
}
