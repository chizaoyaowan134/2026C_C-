#include <cstdio>

int main() {

    int A, B;
    int D;

    scanf("%d%d%d", &A, &B, &D);

    int X = A + B;
    int z[40];
    int num = 0;

    if (X == 0) {
        z[num ++] = 0;
    } else {

        while (X != 0) {
            z[num ++] = X % D;
            X /= D;
        }
    }

    for (int i = num - 1; i >= 0; i --) {
        printf("%d", z[i]);
    }

    return 0;

}