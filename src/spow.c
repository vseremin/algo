#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned pow_mod(unsigned n, unsigned long long stepen, unsigned modul) {
    unsigned mult = n % modul;
    unsigned prod = 1;
    while (stepen > 0) {
        if ((stepen % 2) == 1) {
            prod = (prod * mult) % modul;
            stepen = stepen - 1;
        }
        mult = (mult * mult) % modul;
        stepen = stepen / 2;
    }
    return prod;
}

unsigned long long get_spow(unsigned a, unsigned stepen) {
    int i, j;
    unsigned long long res = 1;
    for (j = 1; j < stepen; j++) {
        for (i = 1; i < stepen; i++) {
            res *= a;
        }
    }
    return res;
}

int main(void) {
    int a, b, c;
    int res;
    unsigned long long stepen;
    res = scanf("%d%d%d", &a, &b, &c);
    assert(res == 3);
    stepen = get_spow(a, b);
    
    printf("%d\n", pow_mod(a, stepen, c));
    return 0;
}
  
