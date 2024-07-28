#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 1000

long long get_abs(long long x) {
    return x >= 0 ? x : -x; 
}

long long get_nod(long long x, long long y) {
    long long q;

    while (x % y != 0) {
        q = x % y;
        x = y;
        y = q;
    }
    return y;
}

void print_fraction(long long x, long long y) {
    long long q;
    while (1) {
        q = x % y;
        printf("%lld ", x / y);
        x = y;
        y = q;
        if (q == 0) {
            printf("\n");
            return;
        }
    }
}

// long long gcd(long long m, long long n, long long* a, long long* b) {
//     long long nod = get_nod(m, n);
//     
//     return nod;
// }

long long gcd(long long m, long long n, long long* a, long long* b) {
    long long a_s, b_s, q, r, t;
    if (m < n) {
        m = m + n;
        n = m - n;
        m = m - n;
    }
    
    *a = 0;
    *b = 1;
    a_s = 1;
    b_s = 0;

    while (1) {
        q = m / n;
        r = m % n;
        if (r == 0)
            return get_abs(n);
        m = n;
        n = r;
        t = a_s;
        a_s = *a;
        *a = t - (q * (*a));
        t = b_s;
        b_s = *b;
        *b = t - q * (*b);
    }

    return get_abs(n);
}

int main(void) {
    long long x = 0, y = 0, x1, y1;
    int res;
    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    printf("%lld\n", get_abs(gcd(x, y, &x1, &y1)));
    printf("%lld %lld\n", y1, x1);
    return 0;
}
