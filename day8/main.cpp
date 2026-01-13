#include <cstdio>

int main() {

    int n, u, d;

    scanf("%d %d %d", &n, &u, &d);

    int ans = 0;
    int count = 0;
    while (1) {

        ans += u;
        count ++;

        if (ans >= n) break;

        ans -= d;
    }

    printf("%d", count);
    return 0;
}