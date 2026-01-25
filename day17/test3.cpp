#include <cstdio>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0; // 简单的输入检查

    // 外层循环：遍历每一行 i
    for (int i = 0; i < n; i++) {

        // 1. 找出这一行两个星星的位置
        // pos1 是正对角线的位置 (i)
        // pos2 是反对角线的位置 (n - 1 - i)
        int pos1 = i;
        int pos2 = n - 1 - i;

        // 2. 确定这一行要打印到哪里结束 (防止行末多余空格)
        // 也就是找 pos1 和 pos2 中较大的那个数
        // C++98 写法：使用三元运算符 (条件 ? 值1 : 值2) 代替 std::max
        int limit = (pos1 > pos2) ? pos1 : pos2;

        // 3. 内层循环：只循环到最远的那个星星为止
        for (int j = 0; j <= limit; j++) {
            // 如果是正对角线 OR 反对角线，就打印星
            if (j == pos1 || j == pos2) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // 每一行结束换行
        printf("\n");
    }

    return 0;
}