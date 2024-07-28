#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long fib_mod(unsigned long long n, unsigned m) {
    unsigned long long first = 0ull, second = 1ull; int idx;
    unsigned long long tmp;
    if (n == 0) return 0ull;
    for (idx = 2; idx <= n; ++idx) {
        tmp = second;
        second = second % m + first % m;
        first = tmp % m;
    }
    return second % m;
}

int get_pisano_period(long long m) {
    long long first = 0, second = 1, tmp; int idx = 0;
    do {
        tmp = second;
        second = (first + second) % m;
        first = tmp;
        idx++;
    } while ((first != 0) || (second != 1));
    return idx;
}

int main(void) {
    long long x, m;
    int res;
    long long fib;

    res = scanf("%lld%lld", &x, &m);
    assert(res == 2);
    res = get_pisano_period(m);
    printf("%lld %d\n", fib_mod(x % res, m), res);

    return 0;
}
