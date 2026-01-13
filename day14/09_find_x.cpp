#include <cstdio>

const int MAXN = 210;
int a[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("%d", i);
            return 0;
        }
    }

    if (i == n) {
        printf("-1");
    }
    return 0;
}