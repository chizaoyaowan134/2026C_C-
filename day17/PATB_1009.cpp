#include <cstdio>
using namespace std;

int main() {
    // 定义一个二维数组存放单词
    // s[80][80]：最多存80个单词，每个单词最长80个字母
    char s[80][80];

    int count = 0; // 记录单词的数量

    // 循环读取
    while (true) {
        // 1. 读入一个单词，存到 s[count] 这一行里
        scanf("%s", s[count]);

        // 计数器加 1，为下个单词腾位置
        count++;

        // 2. 关键点：用 getchar 判断是否换行
        char c = getchar();
        if (c == '\n') {
            break; // 如果读到了换行符，跳出循环
        }
    }

    // 3. 倒着输出
    // 最后一个单词存放在 s[count-1]，所以从 count-1 开始
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", s[i]);

        // 4. 处理空格
        // 如果不是最后一个被输出的单词（也就是原来的第一个单词），就要打印空格
        if (i > 0) {
            printf(" ");
        }
    }

    return 0;
}