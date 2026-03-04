#include <cstdio>

int main() {
    char word[1005][15]; // 第一维开大一点防越界
    int count = 0;

    // 核心修复点：一直读，直到读不到东西（遇到 EOF）为止
    while (scanf("%s", word[count]) != EOF) {
        count++;
    }

    // 倒序输出
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", word[i]);

        // 单词之间加空格
        if (i > 0) {
            printf(" ");
        }
    }

    return 0;
}