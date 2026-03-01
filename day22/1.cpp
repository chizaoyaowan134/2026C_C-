#include <cstdio>

int main() {

    int n, u, d;
    scanf("%d%d%d", &n, &u, &d);

    int count = 0;
    int ans = 0;

    while (1) {

        ans = ans + u;
        count ++;

        if (ans >= n) {
            break;
        }

        ans = ans - d;
    }

    printf("%d", count);

    return 0;






}