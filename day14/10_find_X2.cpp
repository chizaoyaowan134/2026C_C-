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
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("%d", i + 1);
            return 0;
        }
    }

    if (i == n) {
        printf("NO");
    }


    return 0;
}