#include <cstdio>

int main() {
    // 题目说长度不超过 100，为了安全起见，我们开到 105，留出结束符 '\0' 的位置
    char s[105];

    // 使用 scanf 读取连续的字符串。%s 会自动遇到空格或换行停止
    if (scanf("%s", s) != 1) {
        return 0; // 如果没有读到内容，直接退出
    }

    // 1. 初始化：拿第 0 个字符作为基准，计数器设为 1
    char currentChar = s[0];
    int count = 1;

    // 2. 从第 1 个字符开始向后遍历
    // 在 C 风格字符串中，最后一个有效字符后面跟着一个隐藏的 '\0' (空字符)
    // 所以只要字符不是 '\0'，就说明还没走到尽头
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == currentChar) {
            count++; // 如果一样，数量加 1
        } else {
            // 如果不一样，用 printf 按格式输出：字符 + 空格 + 数量 + 换行
            printf("%c %d\n", currentChar, count);

            // 重新把新的字符作为基准，计数器归 1
            currentChar = s[i];
            count = 1;
        }
    }

    // 3. 收尾：把最后一组还没来得及输出的字符和数量打印出来
    printf("%c %d\n", currentChar, count);

    return 0;
}