#include <cstdio>

int main() {

    int n;

    scanf("%d", &n);

    if (n == 0) {

        printf("0");
        return 0;

    }

    int bin[32];

    int idx = 0;

    while (n > 0) {

        bin[idx] = n % 2;
        idx ++;
        n = n / 2;

    }

    for (int i = idx - 1; i >= 0; i --) {
        printf("%d", bin[i]);
    }

    return 0;



}