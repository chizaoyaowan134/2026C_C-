#include <cstdio>
#include <cstring>

int main() {
    char str[15]; // 用来存放读进来的文本，比如 "2D"
    int k;        // 目标进制，比如 16

    if (scanf("%s %d", str, &k) == 2) {
        int dec = 0;               // 准备一个空盒子，用来装最终计算出来的十进制结果
        int len = strlen(str);     // 看看这个文本有几个字符

        // 从左往右，一个字符一个字符地处理
        for (int i = 0; i < len; i++) {
            int val = 0; // 这个变量负责充当“翻译官”，存放翻译后的真实数字

            // 【翻译阶段】
            if (str[i] >= '0' && str[i] <= '9') {
                // 如果是 '0' 到 '9'，减去 '0' 就能得到真实数字
                val = str[i] - '0';
            }
            else if (str[i] >= 'A' && str[i] <= 'F') {
                // 如果是大写字母，算出距离 'A' 的身位，再加上基础值 10
                val = str[i] - 'A' + 10;
            }

            // 【计算阶段】
            // 套用上面讲的核心口诀：往前推一位（乘以进制 k），加上刚翻译好的真实数字 (val)
            dec = dec * k + val;
        }

        // 循环结束，空盒子里装的就是最终结果了
        printf("%d\n", dec);
    }

    return 0;
}