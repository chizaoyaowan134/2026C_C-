#include <cstdio>

const int MAXN = 20;
int a[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int oddSum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            oddSum += a[i];
        }
    }

    printf("%d", oddSum);

    return 0;


}