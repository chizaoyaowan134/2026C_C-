#include <cstdio>

int main() {

    int n;
    scanf("%d", &n);

    int count = 0;
    while (1) {
        if (n == 1) break;

        if (n % 2 == 0) {
            n /= 2;
            count ++;
        } else {
            n = 3 * n + 1;
            n /= 2;
            count ++;
        }
    }

    printf("%d", count);

    return 0;
}