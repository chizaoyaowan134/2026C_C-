#include <stdio.h>

int main() {
    int n;
    char c;

    // 1. 读取输入的边长 N 和字符 C
    // %d 和 %c 中间的空格会自动跳过输入时的空白符，确保准确读取
    scanf("%d %c", &n, &c);

    // 2. 计算行数：50% 并四舍五入
    int rows = (n + 1) / 2;

    // 3. 嵌套循环逐行、逐列打印
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            // 判断当前位置是否在边框上：第一行、最后一行、第一列、最后一列
            if (i == 0 || i == rows - 1 || j == 0 || j == n - 1) {
                printf("%c", c);
            } else {
                // 不在边框上，说明是空心部分，打印空格
                printf(" ");
            }
        }
        // 每一行遍历结束后换行
        printf("\n");
    }

    return 0;
}