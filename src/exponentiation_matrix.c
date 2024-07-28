#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void powNxN(unsigned (*A)[N], unsigned k, unsigned m);

int main() {
  int res, i, j;
  unsigned m, k;
  unsigned A[N][N];

  res = scanf("%u%u", &m, &k);
  assert(res == 2);
  assert(m > 0);

  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j) {
      res = scanf("%u", &A[i][j]);
      assert(res == 1);
    }

  powNxN(A, k, m);

  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j)
      printf("%u ", A[i][j]);
    printf("\n");
  }
}


void multiply_matrix (unsigned (*A)[N], unsigned (*B)[N], unsigned m) {
    unsigned res[N][N] = {0};
    unsigned i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                res[i][j] += (A[i][k] * B[k][j]);
                res[i][j] %= m;
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = res[i][j];
        }
    }
}

void powNxN (unsigned (*A)[N], unsigned stepen, unsigned m) {
    unsigned start_matrix[N][N];
    unsigned i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            start_matrix[i][j] = A[i][j];
        }
    }
    stepen--;
    while (stepen > 0) {
        if (stepen % 2 == 1) {
            multiply_matrix(A, start_matrix, m);
            stepen--;
        } else {
            multiply_matrix(start_matrix, start_matrix, m);
            stepen /= 2;    
        }
    }
}


