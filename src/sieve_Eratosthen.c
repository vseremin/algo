#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
    int n;
    char *s;
};

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20 * CHAR_BIT)
        return 100 * CHAR_BIT;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres) + 1;
}



int is_prime(struct sieve_t* sv, int n) {
    if (n < 2) return 0;
    return !(((sv->s[(n-2) / 8]) >> ((n-2) % 8)) & 1);
}

void fill_sieve(struct sieve_t *sv) {
    int i = 0, k, j;
    for (; i * i < (sv-> n) * 8; i++) {
        if (!((sv->s[i / 8] >> (i % 8)) & 1)) {
            k = (2+i);
            for (j = k+i; j < (sv->n) * 8; j+=k) {
                sv->s[j / 8] = (sv->s[j / 8] | (1 << (j % 8)));
            }
        }
    }
}

int nth_prime(struct sieve_t *s, int N)
{
    int cnt, p, tmp = 0;
    if (N == 1)
        return 2;
    if (N == 2)
        return 3;

    cnt = 2;
    p = 5;

    for (;cnt < N; p++) {
        tmp = 0;
        if (is_prime(s, p)) {;
            cnt += 1;
            if (cnt == N)
                break;
        }
    }

    return p;
}

int main()
{
    int n, outp, i, tmp, k = 0;
    int res;
    struct sieve_t *s;

    res = scanf("%d", &n);
    assert(res == 1);

    s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    assert(s);

    s->n = (sieve_bound(n) / CHAR_BIT) + CHAR_BIT;
    s->s = (char *) calloc(s->n, sizeof(char));
    assert(s->s);

    fill_sieve(s);
    for (i = 2; k < n; i++) {
        tmp = is_prime(s, i);
        k += tmp;
        printf("%d %d\n", i, tmp);
    }

    outp = nth_prime(s, n);
    printf("%d\n", outp);

    free(s->s);
    free(s);
}
