#include <cstdio>

int main() {

    int N;
    char c;
    scanf("%d %c", &N, &c);

    int row = (N + 1) / 2;  // 计算行数

    for (int i = 0; i < N; i++) {
        printf("%c", c);
    }

    printf("\n");

    // 4. 打印中间行（空心）
    // 中间行数量 = 总行数 - 第一行 - 最后一行 = row - 2
    for (int i = 0; i < row - 2; i++) {
        printf("%c", c);        // 左边界
        for (int j = 0; j < N - 2; j++) {
            printf(" ");        // 中间空格
        }
        printf("%c", c);        // 右边界
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        printf("%c", c);
    }

    return 0;




}