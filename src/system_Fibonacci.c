#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long num_fib[51] = {0};

unsigned long long fib(unsigned n) {
    unsigned long long first = 0ull, second = 1ull, tmp; int idx;
    if (n == 0) return 0ull;
    for (idx = 1; idx < n; ++idx) {
        num_fib[idx - 1] = second;
        tmp = second;
        second = second + first;
        first = tmp;
    }
    return second;
}

void printfib(int n) {
    int idx = 0, i = 0;
    fib(50);
    while (n > num_fib[idx+1]) {
        idx++;
    }
    for (i = idx; i >= 0; i--) {
        if (n >= num_fib[i]) {
            printf("1");
            n -= num_fib[i];
            i--;
        } 
        if (i > 0) 
            printf("0");
    }
    printf("\n");
}

int main(void) {
    unsigned n, res;
    res = scanf("%d", &n);
    assert(res==1);
    printfib(n);
    
    
    return 0;
}
 
