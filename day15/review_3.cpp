#include <cstdio>

// int main() {
//
//
//     int n;
//     scanf("%d", &n);
//
//     int x = 1;
//     for (int i = 0; i < n; i ++) {
//
//         x *= 2;
//         x %= 1007;
//
//     }
//
//
//     printf("%d", x);
//
//     return 0;
//
//
//
//
// }


// 快速幂的写法
int main() {

    int n;
    scanf("%d", &n);


    int ans = 1;
    int base = 2;

    while (n > 0) {
        if (n & 1) {
            ans = (ans * base) % 1007;
        }

        base = (base * base) % 1007;

        n = n >> 1;

    }

    printf("%d", ans);

    return 0;

}



