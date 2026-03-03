#include <cstdio>

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 满足以下任一条件时打印 '*':
            // 1. 第一列 (j == 1)
            // 2. 当前行的最后一列 (j == i)
            // 3. 最后一行 (i == n)
            if (j == 1 || j == i || i == n) {
                printf("*");
            } else {
                // 中间空心部分打印空格
                printf(" ");
            }
        }
        // 打印完一行后换行，注意这里直接换行保证了行末没有多余空格
        printf("\n");
    }


    return 0;




}