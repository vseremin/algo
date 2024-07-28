#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
  struct node_t *next;
  int data;
};

int loop_len(struct node_t *top);

int main() {
  int i, nnodes, looppos, res, outcome;
  struct node_t *top = NULL, *cur = NULL, *loopelem = NULL;

  res = scanf("%d%d", &nnodes, &looppos);
  assert(res == 2);
  assert(nnodes >= 0);
  assert(looppos > -2);
  assert(looppos < nnodes);

  if (nnodes > 0) {
    top = calloc(1, sizeof(struct node_t));
    cur = top;
    if (looppos == 0)
      loopelem = cur;
  }

  for (i = 1; i < nnodes; ++i) {
    cur->next = calloc(1, sizeof(struct node_t));
    if (looppos == i)
      loopelem = cur;
    cur = cur->next;
  }

  if (looppos != -1)
    cur->next = loopelem;

  outcome = loop_len(top);
  printf("%d\n", outcome);
}

int loop_len(struct node_t *top) {
    struct node_t *hare = top;
    struct node_t *turtle = top;
    unsigned i, k = 1;
    
    if (hare == NULL) {
        return 0;
    }
    if (hare == turtle->next) {
        return 1;
    }
    while (1) {
        k *= 2;
        for (i = 0; hare != NULL, i < k; i++) {
            hare = hare->next;
            if (hare == NULL) {
                return 0;
            }
            if (hare == turtle)
                return i + 1;
        }
        turtle = hare;
    }
    return 0;
}
