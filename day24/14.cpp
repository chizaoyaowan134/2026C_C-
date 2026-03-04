#include <cstdio>

int main() {
    char word[15]; // 用来接单词的“小筐”
    bool isFirst = true; // 依然是用来控制空格的神器

    // 流水线开始：只要还能读到单词，就继续处理
    while (scanf("%s", word) != EOF) {

        // 1. 处理空格：除了第一个单词，其他的单词前面都加个空格
        if (!isFirst) {
            printf(" ");
        }
        isFirst = false;

        // 2. 核心加工：看看单词的第一个字母（索引为 0）是不是小写字母
        if (word[0] >= 'a' && word[0] <= 'z') {
            // 如果是，就把小写字母强行转换成大写字母
            word[0] = word[0] - 'a' + 'A';
        }

        // 3. 输出加工好的单词
        printf("%s", word);
    }

    return 0;
}