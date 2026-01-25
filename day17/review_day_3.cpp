#include <cstdio>


int main() {

    int n;
    scanf("%d", &n);

    int x = 1;
    for (int i = 0; i < n; i ++) {

        x *= 2;
        x %= 1007;
    }

    printf("%d", x);

    return 0;


}