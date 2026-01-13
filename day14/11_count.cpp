#include <cstdio>

const int MAXN = 25;

int a[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x;
    scanf("%d", &x);

    int i = 0;
    int count = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            count ++;
        }
    }

    printf("%d", count);

    return 0;
}