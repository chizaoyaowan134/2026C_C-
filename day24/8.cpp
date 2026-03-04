#include <cstdio>

int main() {
    int n, k;

    // 读取十进制数 n 和 目标进制 k
    if (scanf("%d %d", &n, &k) == 2) {

        // 老规矩：特判 n = 0 的情况
        if (n == 0) {
            printf("0\n");
            return 0;
        }

        // 神奇的字典（查表法）
        char dict[] = "0123456789ABCDEF";

        char res[32]; // 用来存余数转换后的字符
        int idx = 0;

        // 核心：除 K 取余
        while (n > 0) {
            int rem = n % k;         // 算出余数
            res[idx] = dict[rem];    // 去字典里查出对应的字符，存入数组
            idx++;
            n = n / k;               // 更新 n，继续往下除
        }

        // 逆序输出
        for (int i = idx - 1; i >= 0; i--) {
            printf("%c", res[i]); // 注意这里用 %c 输出字符
        }
        printf("\n");
    }

    return 0;
}