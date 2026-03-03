#include <cstdio>

int main() {

    int a, b;
    scanf("%d%d", &a, &b);


    bool falge = true;
    for (int i = a; i <= b; i ++) {

        int o = i % 10;
        int p = (i / 10) % 10;
        int q = i / 100;

        if (o * o * o + p * p * p + q * q * q == i) {
            if (!falge) {
                printf(" ");
            }

            falge = false;
            printf("%d", i);

        }


    }

    if (falge) {
        printf("NO");
    }

    return 0;

}