#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {

        // 可以根据副对角线的公式i + j = n + 1算出来地址
        int last_star = max(i, n - i + 1);

        for (int j = 1; j <= last_star; j ++) {

            if (j == i || j == n - i + 1) {
                printf("*");
            } else {

                printf(" ");

            }
        }

        printf("\n");

    }

    return 0;

}